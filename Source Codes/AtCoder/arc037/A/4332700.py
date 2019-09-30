N = int(input())

print(sum(map(lambda x: max(0, 80 - int(x)), input().split())))