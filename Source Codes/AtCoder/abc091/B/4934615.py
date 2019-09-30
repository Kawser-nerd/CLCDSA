N = int(input())
s = [input() for i in range(N)]
M = int(input())
t = [input() for i in range(M)]
st = list(set(s) | set(t))

ans = []
for i in st:
    tmp = 0
    tmp += s.count(i)
    tmp -= t.count(i)
    ans.append(tmp)
    
print(max(0, max(ans)))