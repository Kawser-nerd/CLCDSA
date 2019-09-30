n, k = map(int, input().split())
length = list(map(int, input().split()))
list.sort(length, reverse=True)

print(sum([length[i] for i in range(k)]))