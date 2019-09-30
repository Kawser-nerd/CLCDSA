N = int(input())
D = [int(input()) for i in range(N)]

print(sum(D))

print(max(0, max(D)*2 - sum(D)))