
def to_int(l):
    out = 0
    for d in l:
        out = out * 10 + d
    return out

def run_test():
    n = int(input())
    n = [int(c) for c in str(n)]
    assert len(n) >= 1
    start = 0
    for i in range(1, len(n)):
        if n[i] < n[start]:
            break
        elif n[i] > n[start]:
            start = i
    else:
        return to_int(n)
    for j in range(start + 1, len(n)):
        n[j] = 0
    return to_int(n) - 1

for i in range(1, int(input()) + 1):
    print("Case #{}: {}".format(i, run_test()))
