N = int(input())
 
def di():
    A = []
    ax = 0
    ay = 0
    for i in range(N):
        x, y = map(int, input().split())
        A.append((x, y))
        ax += x
        ay += y
 
    ax /= N
    ay /= N
    d = 0
    for (x, y) in A:
        d = max(d, abs(x - ax) ** 2 + abs(y - ay) ** 2)
    return d ** 0.5
 
a = di()
b = di()
print(b / a)