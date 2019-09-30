def check(s):
    s = str(s)
    if s == s[::-1]:
        return True
    else:
        return False
cnt =0
a, b = map(int,input().split())
for i in range(a,b+1):
    if check(i):
        cnt += 1
print(cnt)