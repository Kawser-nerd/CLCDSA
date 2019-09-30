N = int(input())
ans = set()
for x in range(1, min(N+1, 9*18)):
    if N == N-x + sum(int(n) for n in str(N-x)):
        ans.add(N-x)
print(len(ans))
if ans:
    print(*sorted(ans), sep="\n")