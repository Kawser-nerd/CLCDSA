A,B,C = map(int,input().split())
lists = [A,B,C]
K = int(input())
X = 0
for i in range(K):
    X = max(lists) * 2
    for j in range(len(lists)):
        if lists[j] == max(lists):
            lists[j] = X
print(sum(lists))