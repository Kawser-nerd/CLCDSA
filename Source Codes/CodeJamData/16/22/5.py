from collections import defaultdict

def smallest(S):
    return S.replace('?', '0')


def largest(S):
    return S.replace('?', '9')


def solve(A, B):
    n = len(A)
    if n == 0:
        return (0, '', '')

    if A[0] == B[0]:
        if A[0] == '?':
            return min(solve('0' + A[1:], '0' + B[1:]),
                       solve('0' + A[1:], '1' + B[1:]),
                       solve('1' + A[1:], '0' + B[1:]))
        else:
            R = solve(A[1:], B[1:])
            return (R[0], A[0] + R[1], B[0] + R[2])
    elif A[0] == '?':
        x = int(B[0])
        return min(solve(str(x + d) + A[1:], B) for d in [-1, 0, 1] if 0 <= x + d <= 9)
    elif B[0] == '?':
        x = int(A[0])
        return min(solve(A, str(x + d) + B[1:]) for d in [-1, 0, 1] if 0 <= x + d <= 9)
    elif A[0] < B[0]:
        a = largest(A)
        b = smallest(B)
        return (int(b) - int(a), a, b)
    elif A[0] > B[0]:
        a = smallest(A)
        b = largest(B)
        return (int(a) - int(b), a, b)
    else:
        assert False


t = int(input())

for i in range(t):
    A, B = input().split()
    print('Case #{0}: {2} {3}'.format(i + 1, *solve(A, B)))
