def inpl():
    return list(map(int, input().split()))


N = int(input())
TA = [inpl() for i in range(N)]

a, b = TA[0][0], TA[0][1]
for ta, ao in TA[1:]:
    if ta >= a and ao >= b:
        a = ta
        b = ao
    else:
        # elif ta < a and ao < b:
        tmp_a = -(-1 * a // ta)
        tmp_b = -(-1 * b // ao)
        tmp = max(tmp_a, tmp_b)
        a = ta * tmp
        b = ao * tmp
    # elif ta < a and ao >= b:

print(a + b)