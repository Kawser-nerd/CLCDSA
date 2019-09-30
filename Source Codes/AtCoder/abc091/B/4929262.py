N = int(input())
l={}
for _ in range(N):
    s = input()
    if s not in l:
        l[s] = 1
    else:
        l[s] += 1
M = int(input())
for _ in range(M):
    s = input()
    if s in l:
        l[s] -= 1
        
print(max(l.values()) if max(l.values()) >= 0 else 0)