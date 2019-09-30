H, W = [int(_) for _ in input().split()]
N = int(input())
A = [int(_) for _ in input().split()]
B = []
for i in range(N):
    B += [i + 1] * A[i]
for j in range(H):
    print(' '.join(map(str, B[j * W:(j + 1) * W][::(-1)**(1&j)])))