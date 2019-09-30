N = int(input())
S = input()

def f(s, i):
    if i % 3 == 1:
        return 'a' + s + 'c'
    elif i % 3 == 2:
        return 'c' + s + 'a'
    elif i % 3 == 0:
        return 'b' + s + 'b'

memo = []
init = 'b'
for i in range(1,100):
    memo.append(init)
    init = f(init, i)

if S in memo:
    print(memo.index(S))
else:
    print(-1)