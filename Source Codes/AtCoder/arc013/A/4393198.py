N, M, L = map(int, input().split())
P, Q, R = map(int, input().split())

tmp = -1

tmp = max(int((N//P) * (M//Q) * (L // R)), tmp)
tmp = max(int((N//P) * (M//R) * (L // Q)), tmp)
tmp = max(int((N//Q) * (M//P) * (L // R)), tmp)
tmp = max(int((N//Q) * (M//R) * (L // P)), tmp)
tmp = max(int((N//R) * (M//Q) * (L // P)), tmp)
tmp = max(int((N//R) * (M//P) * (L // Q)), tmp)
print(tmp)