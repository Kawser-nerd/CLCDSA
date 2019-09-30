A, B, K, L = map(int, input().split())
print(min(B*(K//L)+A*(K%L), B*(K//L+1)))