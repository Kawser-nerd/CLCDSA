#A 
"""
n = int(input())
print(n-1)
"""

#B
"""
a = input()
if a == "a":
    print(-1)
else:
    print("a")
"""

#C
"""
r, c = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
field = ["#"*(c+2)]+["#"+input()+"#" for i in range(r)]+["#"*(c+2)]
check =[[0 for i in range(c+2)] for i in range(r+2)]
import queue
player = queue.Queue()

player.put((sy, sx, 0))
while not player.empty():
    now = player.get()
    x = [0, 1, 0, -1]
    y = [-1, 0, 1, 0]
    for i in range(4):
        if field[now[0] + y[i]][now[1] + x[i]] == "." and check[now[0] + y[i]][now[1] + x[i]] == 0:
            player.put((now[0] + y[i], now[1] + x[i], now[2] + 1))
            check[now[0] + y[i]][now[1] + x[i]] = 1
            if now[0] + y[i] == gy and now[1] + x[i] == gx:
                print(now[2] + 1)
                quit()
"""

#D
a, b = map(str, input().split())
nums = [0, 1, 2, 3, 4, 4, 5, 6, 7, 8]
nums1 = [0, 1, 2, 3, 3, 4, 5, 6, 7, 7]
ans = 0
for i in range(len(b)):
    ans += nums[int(b[i])] * (8 ** (len(b) - i - 1))
    if b[i] == "4" or b[i] == "9":
        ans -= 1
        break
for i in range(len(a)):
    ans -= nums[int(a[i])] * (8 ** (len(a) - i - 1))
    if a[i] == "4" or a[i] == "9":
        break
ans = int(b) - int(a) - ans
print(ans)