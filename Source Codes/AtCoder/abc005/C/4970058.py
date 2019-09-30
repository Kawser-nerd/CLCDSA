T = int(input())
N = int(input())
A = list(reversed(list(map(int, input().split()))))
M = int(input())
B = list(map(int, input().split()))

for b in B:
    while A:
        a = A.pop()
        if b in range(a, a + T + 1):
            break
    else:
        print('no')
        break
else:
    print('yes')