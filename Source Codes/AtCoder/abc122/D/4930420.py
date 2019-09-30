N = int(input())

MOD = int(1e9+7)

tokens = ['A','C','G','T']

suffixes = []
for suffix_1 in tokens:
    for suffix_2 in tokens:
        for suffix_3 in tokens:
            suffixes.append(suffix_1+suffix_2+suffix_3)

dp = [[0 for _ in suffixes] for _ in range(N+1)]

reverse_index = {}
for i,s in enumerate(suffixes):
    reverse_index[s] = i

def pprint(dp):
    N = len(dp)
    M = len(dp[0])

    for i in dp:
        st = ""
        for j in i:
            st += str(j)
            st += " "
        print(st)

for i,s in enumerate(suffixes):
    if not s in ['AGC', 'ACG', 'GAC']:
        dp[3][i]  = 1

valid_str_4 = set()

def swap(s, i ,j):
    s_new = list(s)
    s_new[i], s_new[j] = s[j], s[i]
    return ''.join(s_new)

def valid(str4):
    if 'AGC' in str4:
        return False
    for i in range(3):
        s_new = swap(str4, i, i+1)
        if 'AGC' in s_new:
            return False
    return True

for s in suffixes:
    for c in tokens:
        ss = s+c
        if valid(ss):
            valid_str_4.add(ss)

for n in range(4, N+1):
    for s in suffixes:
        for c in tokens:
            ss = s+c
            if ss in valid_str_4:
                dp[n][reverse_index[ss[1:]]] += dp[n-1][reverse_index[s]]

print(sum(dp[N]) % MOD)