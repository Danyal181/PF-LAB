#include<stdio.h>
int main(){
	int i;
for (i = 1; i <= 13; i++) {
  if (i == 4|| i == 6|| i == 7 || i ==9||i == 10 ||i == 11 || i ==12) {
    continue;
  }
  printf("%d\n", i);
}
}

