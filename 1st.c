#include<stdio.h>
#include<stdlib.h>

/* アセンブラを生成する*/

/*argcはコマンドライン引数の数,argvはコマンドライン引数を表す*/
int main(int argc, char **argv) {
  if(argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n"); /* stderrは標準エラー>    出力*/
    return 1;
   }
  char *p = argv[1];
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");
  printf("  mov rax, %ld\n", strtol(p, &p, 10)); /*atoiは文字列を数値型へ変換*/
  while(*p) {
    if(*p == '+') {
      p++;
      printf("  add rax, %ld\n", strtol(p, &p, 10));
      continue;
      }

    if(*p == '-') {
      p++;
      printf("  sub rax, %ld\n", strtol(p, &p, 10));
      continue;
      }

    fprintf(stderr, "予期しない文字です: '%c'\n", *p);
      return 1;
    }

    printf("  ret\n");
    return 0;
    }

