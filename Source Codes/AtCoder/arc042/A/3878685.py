N,M = (int(i) for i in input().split())

a = []
for i in range(M):
    inputa = int(input())
    a.append(inputa)

thread = []
appeared = set()

for i in range(M):
    if a[M-1 -i] not in appeared:
        thread.append(a[M-1-i])
        appeared.add(a[M-1-i])
    else:
        continue

for i in range(1,N+1):
    if i not in appeared:
        thread.append(i)
    
for i in range(N):
    print(thread[i])