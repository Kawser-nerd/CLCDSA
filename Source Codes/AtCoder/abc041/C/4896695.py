N = int(input())
a = list(map(int, input().split()))
li = []
for i in range(N):
    li.append([i + 1, a[i]])
li.sort(key = lambda x:x[1], reverse = True)
for i in range(N):
    print(li[i][0])