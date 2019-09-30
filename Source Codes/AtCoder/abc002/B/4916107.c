int main() {
	char word[6] = { 'a','i','u','e','o' };
	char talk[31];
	scanf("%s", talk);

	for (int i = 0; i < strlen(talk); i++) {
		if (talk[i] != word[0] && talk[i] != word[1] && talk[i] != word[2] && talk[i] != word[3] && talk[i] != word[4]) {
			printf("%c", talk[i]);
		}
	}

	printf("\n");
	return 0;

} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%s", talk);
  ^
./Main.c:4:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:22: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  for (int i = 0; i < strlen(talk); i++) {
                      ^
./Main.c:6:22: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:6:22: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:8:4: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    printf("%c", talk[i]);
    ^
./Main.c:8:4: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:8:4: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:12:2: warning: incompatible implicit declaration of built-in functi...