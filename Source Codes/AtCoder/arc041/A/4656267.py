x, y = map(int, input().split())
k = int(input())
print(x+k if y>=k else x+2*y-k)