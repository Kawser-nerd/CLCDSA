N = int(input())
an = map(int, input().split())

san = sorted(an)
print(sum(san[i] for i in range(N, N*3, 2)))