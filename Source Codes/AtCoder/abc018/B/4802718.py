s = input()
N = int(input())
for _ in range(N):
  x , y = map(int, input().split())
  x -= 1
  y -= 1
  s =s[:x] + s[x:y+1][::-1] + s[y+1:]
print(s)