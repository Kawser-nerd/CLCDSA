N = int(input())
A = list(map(int, input().split()))

odds = sum([a % 2 for a in A])
evens = sum([(a+1) % 2 for a in A])

if len(A) == 1:
    print('YES')
    exit()
if odds % 2 == 0:
    print('YES')
    exit()
print('NO')