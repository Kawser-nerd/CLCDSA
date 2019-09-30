N, A, B = (int(i) for i in input().split())
h = [0]*N
for i in range(N):
    h[i] = int(input())
hmax = max(h)
A = A-B

def func(k):
    hn = [a - k*B for a in h]
    res = 0
    for i in range(N):
        if hn[i] > 0:
            res += (hn[i]-1+A)//A
    return res <= k

left = 0
right = hmax//B + 1
while True:
    if left == right:
        break
    half = (left + right)//2
    if func(half):
        right = half
    else:
        left = half + 1
print(left)