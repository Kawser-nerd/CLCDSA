Q, H, S, D = map(int, input().split())
N = int(input())
x = min([4*Q, 2*H, S, D//2])
if x == (D//2):
  print((N//2)*D + (N%2)*min([4*Q, 2*H, S]))
else:
  print(N*x)