n = int(input())
A = list(input().split())

even = [A[i] for i in range(n) if i % 2 == 0]
odd = [A[i] for i in range(n) if i % 2 == 1]

if n % 2 == 0:
    print(' '.join(list(reversed(odd)) + even))
else:
    print(' '.join(list(reversed(even)) + odd))