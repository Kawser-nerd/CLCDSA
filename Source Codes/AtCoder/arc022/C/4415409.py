N = int(input())
X = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    X[a-1].append(b-1)
    X[b-1].append(a-1)

def farthest(i):
    L = [-1] * N
    L[i] = 0
    d = 0
    post = [i]
    while len(post) > 0:
        d += 1
        pre = post
        post = []
        for j in pre:
            for k in X[j]:
                if L[k] < 0:
                    L[k] = d
                    post.append(k)
        
    return pre[0]
    return (pre[0], d-1)

s = farthest(0)
t = farthest(s)
print(s+1, t+1)