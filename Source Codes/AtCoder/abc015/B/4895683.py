N = int(input())
a = list(map(int, input().split()))

print(-(-sum(a) // (N - a.count(0))))