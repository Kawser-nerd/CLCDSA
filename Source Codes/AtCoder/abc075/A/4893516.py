A, B, C = map(int, input().split())
print(A if B == C else B if C == A else C)