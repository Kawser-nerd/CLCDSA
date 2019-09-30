import itertools

n = int(input())
MOD = 10 ** 9 + 7

ng_patterns3 = ['AGC', 'ACG', 'GAC']
ng_patterns4 = ['AAGC', 'AACG', 'ATGC', 'AGAC', 'AGTC', 'AGGC', 'AGCA', 'AGCT', 'AGCG', 'AGCC', 'ACGA', 'ACGT', 'ACGG',
                'ACGC', 'TAGC', 'TACG', 'TGAC', 'GAGC', 'GACA', 'GACT', 'GACG', 'GACC', 'GGAC', 'CAGC', 'CACG', 'CGAC']


# ???3????????????????????
# ???3??????????????????
def main():
    # ???
    counts = {}
    for li in itertools.product('ATGC', repeat=3):
        s = ''.join(li)
        if s not in ng_patterns3:
            counts[s] = 1

    # 1???????
    for _ in range(3, n):
        new_counts = {s: 0 for s in counts.keys()}
        for s3, count in counts.items():
            for c in 'ATGC':
                s4 = s3 + c
                if s4 not in ng_patterns4:
                    new_counts[s4[-3:]] += count % MOD
        counts = new_counts

    print(sum([c for c in counts.values()]) % MOD)


if __name__ == '__main__':
    main()