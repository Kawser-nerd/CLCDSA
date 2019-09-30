N, K = map(int, input().rstrip().split())
l = list(map(int, input().rstrip().split()))
l.sort(reverse=True)
answer = 0
for i in range(K):
    answer += l[i]
print(answer)