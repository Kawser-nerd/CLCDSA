b = list(map(int, input().split()))
N = int(input())
a = [int(input()) for _ in range(N)]
new_a = []
for e in a:
    s = ''
    for c in list(str(e)):
        s += str(b.index(int(c)))
    new_a.append(int(s))
for c,d in sorted(zip(new_a,a)):
    print(d)