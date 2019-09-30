n = int(input())
p = [int(input()) for i in range(n)]
print(int(sum(p) - max(p)/2))