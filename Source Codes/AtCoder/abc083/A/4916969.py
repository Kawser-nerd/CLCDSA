A, B, C, D = map(int, input().split())
L, R = A+B, C+D
print(["Balanced", "Left", "Right"][(R<L) + -(R>L)])