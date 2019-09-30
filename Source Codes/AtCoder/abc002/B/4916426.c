int main(void)
{

	char moji[30];
	char moji2[30];
	int j=0;
	scanf("%s", moji);
	
	for (int i = 0;moji[i] != '\0';i++) {
		if (moji[i] == 'a'|| moji[i] == 'i' || moji[i] == 'u' || moji[i] == 'e' || moji[i] == 'o') {
		
		}
		else {
			moji2[j] = moji[i];
			j++;
		}
	}
	moji2[j] = '\0';
	printf("%s\n", moji2);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%s", moji);
  ^
./Main.c:7:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:7:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:19:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%s\n", moji2);
  ^
./Main.c:19:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:19:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’