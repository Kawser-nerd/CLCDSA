N, K = map(int, input().split())
s = []
for i in range(N):
    x = int(input())
    s.append(x)

def multi(li):
    ret = 1
    for i in li:
        ret *= i
    return ret

if 0 in s:
    print(N)
    quit()

j = 0
ans = 0
score = 1
for i in range(len(s)):
    if j < i:
        j = i
    while True:
        if j+1 <= N and score * s[j] <= K:
            score *= s[j]
            j += 1
            ans = max(ans, j-i)
        else:
            if not i == j:
                score //= s[i]
            break

print(ans)