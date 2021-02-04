#include <stdio.h>
#include <ctype.h> //引入字元測試與轉換函數標頭檔
 
struct student{
  int id;
  char name[10];
};
 
int main(void) {
  student john = {291, {'j', 'o', 'h', 'n', '\0'}};
  printf("學號：%d\n", john.id);
  printf("姓名：%s\n", john.name);
  printf("\n");
 
  john.id = 1000 + john.id; //把原學號 +1000
  for(int i = 0; john.name[i] != '\0'; i++){ //只要變數不是\0
    john.name[i] = toupper(john.name[i]); //就把john陣列中的小寫都變大寫
  }
 
  printf("新學號：%d\n", john.id); //印出改過後的學號
  printf("新姓名：%s\n", john.name); //印出改過後的名字
 
  return 0;
}