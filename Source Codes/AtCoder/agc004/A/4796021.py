A, B, C = map(int, input().split())
print(min(A*B*(C - 2*(C//2)),B*C*(A-2*(A//2)),C*A*(B-2*(B//2))))