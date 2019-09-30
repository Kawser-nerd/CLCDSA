N , MOD = int(input()), int(1e9+7)

all_suffix = []
base = ['A', 'C', 'G', 'T']

for char1 in base:
    for char2 in base:
        for char3 in base:
            all_suffix.append(char1+char2+char3)

len_all_suffix = len(all_suffix)

def judge(last4):
    for i in range(4):
        tmp = list(last4)
        if i >= 1:
            tmp[i-1], tmp[i] = tmp[i], tmp[i-1]
        if ''.join(tmp).find('AGC') >= 0:
            return False
    return True

dp = [[0 for i in range(len_all_suffix)] for i in range(N-2)]

for i in range(len_all_suffix):
    if all_suffix[i]!='AGC' and all_suffix[i]!='GAC' and all_suffix[i]!='ACG':
        dp[0][all_suffix.index(all_suffix[i])] += 1

for i in range(1, N-2):
    for j in range(len_all_suffix):
        for char in base:
            if judge(all_suffix[j]+char):
                k = all_suffix.index(all_suffix[j][1:]+char)
                dp[i][k] += dp[i-1][j] % MOD

print(sum(dp[N-3])%MOD)