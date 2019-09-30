n = int(input())
A = input().split(' ')

if n == 1:
    ans = A[0]
    print(ans)
    exit()
else:
    A_odd = A[::2]
    A_even = A[1::2]
    if n % 2 == 0:
        ans = A_even[::-1] + A_odd
    else:
        ans = A_odd[::-1] + A_even
    print(' '.join(ans))