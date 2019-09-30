def check(s, t):
    from collections import Counter
    sc = Counter(s)
    tc = Counter(t)
    return sorted(sc.values()) == sorted(tc.values())

print(['No','Yes'][check(input(),input())])