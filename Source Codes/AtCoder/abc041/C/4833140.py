N = int(input())
a = list(map(int, input().split()))
A = []
for i, ai in enumerate(a):
    A.append([ai, i+1])

for ai in sorted(A, key=lambda ai: -ai[0]):
    print(ai[1])