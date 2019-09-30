N = int(input())
a = list(map(int, input().split()))
a = list(map(lambda x: x % 2, a))
print('NO' if sum(a) % 2 == 1 else 'YES')