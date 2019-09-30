import bisect

def bump(T, x):
    if T == []:
        return [[x]]
    else:
        i = bisect.bisect_right(T[0], x)
        if i == len(T[0]):
            return [T[0] + [x]] + T[1:]
        else:
            y = T[0][i]
            T[0][i] = x
            return [T[0]] + bump(T[1:], y)

N = int(input())
w = [None for i in range(N)]
for i in range(N):
    w[i] = int(input())

T = []
for i in range(N):
    T = bump(T, w[N - 1 - i])
print(len(T))