n = int(input())
a = list(map(int, input().split()))
a.sort()
a.reverse()
alice = [a[i] for i in range(0, n, 2)]
bob = [a[i] for i in range(1, n, 2)]
print(sum(alice) - sum(bob))