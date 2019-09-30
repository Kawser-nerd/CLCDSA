# time complexity: O((lgN)^4)
# space complexity: O((lgN)^2)

def digit_sum(num):
    ds = 0
    while num > 0:
        ds += num % 10
        num //= 10
    return ds


K = int(input())
candidates = []
digit_sums = []
for i in range(15):
    base = 10**i
    for j in range(1, 150):
        candidate = j * base + (base - 1)
        candidates.append(candidate)

candidates = sorted(list(set(candidates)))
digit_sums = [digit_sum(candidate) for candidate in candidates]

snuke_nums = []
smaller_as_snuke = lambda n, m, ds_n, ds_m: True if n * ds_m <= m * ds_n else False
for i, candidate in enumerate(candidates):
    ds_cand = digit_sums[i]
    for j in range(i + 1, len(candidates)):
        other_num = candidates[j]
        ds_other = digit_sums[j]
        if not smaller_as_snuke(candidate, other_num, ds_cand, ds_other):
            break
    else:
        snuke_nums.append(candidate)

for snuke_num in snuke_nums[:K]:
    print(snuke_num)