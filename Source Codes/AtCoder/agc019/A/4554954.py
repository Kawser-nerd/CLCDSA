Q, H, S, D = map(int, input().split())
N = int(input())
print(min([Q * 4, H * 2, S]) * (N % 2) + min([min([Q * 4, H * 2, S]) * 2, D])*int(N / 2))