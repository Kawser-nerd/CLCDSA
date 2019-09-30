N, L = map(int, input().split())
S = [input().rstrip() for _ in range(N)]
print(''.join(sorted(S)))