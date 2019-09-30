from collections import defaultdict

def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret


def see_A(A, conn):
    first = {}
    last = {}
    for i in range(len(A)):
        val = A[i]
        if val not in first:
            first[val] = i
        else:
            conn[last[val]].add(i)

        if val > 1:
            pre_val = val - 1
            conn[i].add(last[pre_val])

        last[val] = i


def see_B(B, conn):
    B = list(reversed(B))
    L = len(B)
    first = {}
    last = {}
    for i in range(len(B)):
        val = B[i]
        if val not in first:
            first[val] = i
        else:
            conn[L - 1 - last[val]].add(L - 1 - i)

        if val > 1:
            pre_val = val - 1
            conn[L - 1 - i].add(L - 1 - last[pre_val])

        last[val] = i


def quick(A):
    l = len(A)
    m = defaultdict(list)

    for i in range(len(A)):
        val = A[i]
        m[val].append(i)

    assigned = [0] * l
    now = 1
    for _l in range(l + 1):
        v = m[_l]
        for idx in reversed(v):
            assigned[idx] = now
            now += 1
    return assigned



def cal(conn, N):
    q = []
    now = 1
    for i in range(N):
        if len(conn[i]) == 0:
            q.append(i)

    q.sort()

    assigned = [0] * N
    while q:
        idx = q[0]
        q = q[1:]

        assigned[idx] = now
        now += 1

        for i in range(N):
            if idx in conn[i]:
                conn[i].remove(idx)
                if len(conn[i]) == 0:
                    q.append(i)

        q.sort()

    return assigned



def main():
    T = input()

    for _ in range(T):
        N = input()
        A = read_array(int)
        B = read_array(int)

        conn = [set() for i in range(N)]
        
        see_A(A, conn)
        see_B(B, conn)


        ans = cal(conn, N)

        print 'Case #%d: ' % (_+1),
        for val in ans:
            print val,
        print ''

"""        see_A(A, conn)
        see_B(B, conn)
"""




main()
