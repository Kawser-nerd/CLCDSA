# ???????????????????
N = int(input())

f = lambda x: sum(map(int, str(x)))

l = []
for x in range(max(1, N-162), N):
    # print(N-i)
    if x+f(x) == N:
        l.append(x)

print(len(l))
for l_i in l:
    print(l_i)