S = input()
T = input()
S_a, S_b = [0], [0]
T_a, T_b = [0], [0]

for s in S:
    if s == "A":
        S_a.append(S_a[-1] + 1)
        S_b.append(S_b[-1])
    if s == "B":
        S_a.append(S_a[-1])
        S_b.append(S_b[-1] + 1)

for t in T:
    if t == "A":
        T_a.append(T_a[-1] + 1)
        T_b.append(T_b[-1])
    if t == "B":
        T_a.append(T_a[-1])
        T_b.append(T_b[-1] + 1)


def calc(na, nb):
    if na > nb:
        diff = na- nb
        if diff % 3 == 0:
            return ""
        elif (diff % 3) % 2 == 0:
            return "B"
        else:
            return "A"
    else:
        diff = nb - na
        if diff % 3 == 0:
            return ""
        elif (diff % 3) % 2 == 0:
            return "A"
        else:
            return "B"


Q = int(input())
for q in range(Q):
    a, b, c, d = map(int, input().split())
    sa = S_a[b] - S_a[a - 1]
    sb = S_b[b] - S_b[a - 1]
    ta = T_a[d] - T_a[c - 1]
    tb = T_b[d] - T_b[c - 1]

    SQ = calc(sa, sb)
    TQ = calc(ta, tb)

    print("YES" if SQ == TQ else "NO")