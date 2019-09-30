N,Z,W = map(int,input().split())
src = list(map(int,input().split()))

s1 = abs(src[-1] - W)
s2 = 0 if N==1 else abs(src[-2] - src[-1])

print(max(s1,s2))