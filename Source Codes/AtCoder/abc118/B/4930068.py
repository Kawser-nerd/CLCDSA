N, M = map(int, input().split())
lstinlst = []

for i in range(N):
    lst = list(input().split())
    lstinlst.append(lst[1:])

ttl = set(lstinlst[0])
for i in range(N - 1):
    ttl = set(lstinlst[i]) & set(lstinlst[i + 1]) & ttl

print(len(ttl))