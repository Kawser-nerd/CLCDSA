#include <stdio.h>

int main(void) {
	int T, caseCount;
	if (scanf("%d", &T) != 1) return 1;
	for (caseCount = 1; caseCount <= T; caseCount++) {
		int N;
		int cur;
		int flags = (1 << 10) - 1;
		if (scanf("%d", &N) != 1) return 1;
		printf("Case #%d: ", caseCount);
		cur = 0;
		if (N == 0) {
			puts("INSOMNIA");
		} else {
			while (flags) {
				int digits = (cur += N);
				while (digits) {
					flags &= ~(1 << (digits % 10));
					digits /= 10;
				}
				if (cur > 1000000000) {
					cur = -1;
					break;
				}
			}
			if (cur < 0) {
				puts("GIVE UP");
			} else {
				printf("%d\n", cur);
			}
		}
	}
	return 0;
}

/*
check if the sequence is finite with the last two digits except for 0 (Python 3)

for n in range(1, 100):
    if n % 10 != 0:
        flags = (1 << 10) - 1
        cur = n
        while flags != 0:
            flags &= ~(1 << (cur % 10))
            flags &= ~(1 << ((cur // 10) % 10))
            cur += n
            if cur > 100000:
                cur = "GIVE UP"
                break
        print(str(n) + " -> " + str(cur))

Hmmm, the sequence will be finite for positive N unless the last two digits are 25 and 75.
Let me examine with one more digit with last digits 25 and 75.

for m in range(0, 20):
    flags = (1 << 10) - 1
    n = m * 50 + 25
    cur = n
    while flags != 0:
        flags &= ~(1 << (cur % 10))
        flags &= ~(1 << ((cur // 10) % 10))
        flags &= ~(1 << ((cur // 100) % 10))
        cur += n
        if cur > 100000:
            cur = "GIVE UP"
            break
    print(str(n) + " -> " + str(cur))

Hmmm, 125, 375, 625 and 875 are the exceptions.

OK, just run the program with all possible N without further consideration and see if it works well!

max = 1000000
print(max + 1)
for i in range(0, max + 1):
    print(i)

*/
