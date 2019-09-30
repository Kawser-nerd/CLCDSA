num_terms, max_value = map(int, input().split())
coef = [int(a) for a in input().split()]

res = 0
for i in range(40, -1, -1):
    num_bits = 0
    for a in coef:
        num_bits += ((a >> i) & 1)
    cand = 2**i
    if (num_terms-num_bits) > num_bits and cand <= max_value:
        res += (num_terms - num_bits)*cand
        max_value -= cand
    else:
        res += num_bits*cand

print(res)