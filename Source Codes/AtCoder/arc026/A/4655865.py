N, A, B = map(int, input().split())
numDy = min(N, 5)

print(A*(N-numDy)+B*numDy)