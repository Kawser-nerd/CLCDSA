A,B,C = map(str, input().split())
print('YES' if A[-1] == B[0] and B[-1] == C[0] else 'NO')