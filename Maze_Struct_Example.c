#include <stdio.h>
#include <ctype.h> //�ޤJ�r�����ջP�ഫ��Ƽ��Y��
 
struct student{
  int id;
  char name[10];
};
 
int main(void) {
  student john = {291, {'j', 'o', 'h', 'n', '\0'}};
  printf("�Ǹ��G%d\n", john.id);
  printf("�m�W�G%s\n", john.name);
  printf("\n");
 
  john.id = 1000 + john.id; //���Ǹ� +1000
  for(int i = 0; john.name[i] != '\0'; i++){ //�u�n�ܼƤ��O\0
    john.name[i] = toupper(john.name[i]); //�N��john�}�C�����p�g���ܤj�g
  }
 
  printf("�s�Ǹ��G%d\n", john.id); //�L�X��L�᪺�Ǹ�
  printf("�s�m�W�G%s\n", john.name); //�L�X��L�᪺�W�r
 
  return 0;
}