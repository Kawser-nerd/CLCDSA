N = int(input())
inputs = [int(input()) for _ in range(N)]

def process():
    global right, ans
    right += 1
    if right == N - 1:
        ans = max(ans, right - left + 1)
        print(ans)
        exit()

left = 0
right = 0
ans = 1
while right < N - 1:
    while inputs[right] < inputs[right + 1]:
        process()
    while inputs[right] > inputs[right + 1]:
        process() 
    ans = max(ans, right - left + 1)
    left = right
    right += 1

print(ans)