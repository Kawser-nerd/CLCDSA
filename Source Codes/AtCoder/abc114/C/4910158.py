N = int(input())


def dfs(s):
    if int(s) > N:
        return 0
    ct = 1 if all(s.count(a) for a in '357') else 0
    ct += dfs(s+'3')
    ct += dfs(s+'5')
    ct += dfs(s+'7')
    return ct


print(dfs('0'))