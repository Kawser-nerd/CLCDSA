if __name__ == "__main__":
    N = int(input())
    n = 40
    for i in range(40, -1, -1):
        if (N >= (1 << i) - 1):
            n = i
            break
    data = []
    for i in range(n):
        data.append(i + 1)
    N -= (1 << n) - 1
    tmp = n
    for i in range(n - 1, -1, -1):
        if (N < (1 << i)):
            continue
        tmp += 1
        data = data[:i] + [tmp] + data[i:]
        N -= (1 << i)
    ans = []
    for x in range(len(data)):
        ans.append(x + 1)
    ans = ans + data
    print (len(ans))
    print (" ".join(map(str, ans)))