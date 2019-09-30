#include <stdio.h>
#include <string.h>

typedef long long ll;

char A[200005];

int alphabet[26];
ll sequence[200005];

int main() {

	scanf("%s",A);

	int len = strlen(A);

	int i;

	for (i = 0; i < len; i++) {
		alphabet[A[i]-'a']++;
	}
	sequence[1] = 0ll;
	for (i = 2; i < 200005; i++) {
		sequence[i] = sequence[i - 1] + (ll)(i-1);
	}

	ll len2 = (ll)len;

	ll ans = (len2*(len2 - 1ll) / 2ll) + 1ll;

	for (i = 0; i < 26; i++) {
		if (alphabet[i] >= 2) {
			ans -= sequence[alphabet[i]];
		}
	}

	printf("%lld\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",A);
  ^