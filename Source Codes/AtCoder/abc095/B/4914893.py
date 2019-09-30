N,X = map(int,input().split())
lists = []
for i in range(N):
    m = int(input())
    lists.append(m)
X -= sum(lists)
if X > 0:
    amari = X // min(lists)
    print(len(lists) + amari)
else:
    print(len(lists))