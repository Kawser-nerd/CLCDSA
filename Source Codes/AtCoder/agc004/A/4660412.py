A, B, C = map(int, input().split())
print(min((A%2)*B*C, A*(B%2)*C, A*B*(C%2)))