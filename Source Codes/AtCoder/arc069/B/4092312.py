#!/usr/bin/env python3

def main():
    n = int(input())
    s = input()
    s = list(s)
    s.append(s[0])
    for d0 in ["S", "W"]:
        for d1 in ["S", "W"]:
            pat = wrap(n, s, d0, d1)
            if pat[0] == pat[n] and pat[1] == pat[n + 1]:
                res = "".join(pat[:n])
                print(res)
                return
    print("-1")

def wrap(n, s, d0, d1):
    ds = [d0, d1]
    for i in range(2, n + 2):
        d = get_dnext(ds[i - 2], ds[i - 1], s[i - 1])
        ds.append(d)
    assert len(ds) == n + 2
    return ds

def get_dnext(dpre, di, si):
    if di == "S" and si == "o":
        dnext = dpre
    elif di == "S" and si == "x":
        dnext = inv(dpre)
    elif di == "W" and si == "o":
        dnext = inv(dpre)
    elif di == "W" and si == "x":
        dnext = dpre
    else:
        raise Exception
    return dnext

def inv(d):
    return "W" if d == "S" else "S"

main()