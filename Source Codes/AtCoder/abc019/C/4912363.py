from collections import Counter
N = int(input())
an = list(map(int,input().split()))
ans = 0
for i in range(N):
    while (an[i] & 1) == 0:
        an[i] = (an[i]>>1)
ac = Counter(an)
print(len(ac))