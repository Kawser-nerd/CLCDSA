A, B = map(int, input().split())
print(max( max(A+B, A-B), A*B ))