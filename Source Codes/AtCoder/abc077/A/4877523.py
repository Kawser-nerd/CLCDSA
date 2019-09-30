C = [list(input()) for i in range(2)]
print('YES' if C[0][2] == C[1][0] and C[0][1] == C[1][1] and C[0][0] == C[1][2] else 'NO')