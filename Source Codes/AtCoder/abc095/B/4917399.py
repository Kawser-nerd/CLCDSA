n, x = map(int, input().split())
m = [ int(input()) for _ in range(n) ]
print(n+(x-sum(m))//min(m))