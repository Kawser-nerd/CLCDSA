N, M = map(int, input().split())
preA = [int(input()) for i in range(M)]
A = set()
for a in reversed(preA):
    if a not in A:
        print(a)
        A.add(a)

setA = set(A)
setN = set([i for i in range(1, N + 1)])
diff = sorted(list(setN - setA))
 
for d in diff:
    print(d)