import bisect

N = input()
Ls = map(int,input().split(" "))
Ls = sorted(Ls)
ans = sum([L for i,L in enumerate(Ls) if i%2 == 0])
print(ans)