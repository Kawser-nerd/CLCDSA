import sys

def main():
    input = sys.stdin.readline
    N, C = map(int, input().split())
    dic = [[] for _ in range(C + 1)]
    for _ in range(N):
        s, t, c = input().split()
        dic[int(c)].append([int(s), int(t)])
    for c in range(C + 1):
        l = len(dic[c])
        if l == 1:
            continue
        dic[c] = sorted(dic[c])
        i = 0
        while i < l - 1:
            if i < l - 1 and dic[c][i][1] == dic[c][i + 1][0]:
                dic[c][i + 1][0] += 1
            else:
                i += 1
    f = [0 for _ in range(100002)]
    for c in range(C + 1):
        for t in dic[c]:
            f[t[0]] += 1
            f[t[1] + 1] -= 1
    ans = 0
    for i in range(1, 100001):
        f[i] += f[i - 1]
        if ans < f[i]:
            ans = f[i]
    print(ans)

if __name__ == "__main__":
    main()