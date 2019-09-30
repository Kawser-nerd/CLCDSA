A, B, C, D = map(int, input().split())
left = A + B
right = C + D
print('Left' if left > right else 'Right' if left < right else 'Balanced')