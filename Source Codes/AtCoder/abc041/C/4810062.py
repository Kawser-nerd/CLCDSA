N = int(input())
a = [[i+1, int(x)] for i, x in enumerate(input().split())]
a.sort(reverse=True, key=lambda x: x[1])
for x in a:
    print(x[0])