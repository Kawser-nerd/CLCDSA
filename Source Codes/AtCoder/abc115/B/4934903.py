n = int(input())
l = [int(input()) for i in range(n)]
l.sort(reverse=True)
l[0] = l[0] // 2

print(sum(l))