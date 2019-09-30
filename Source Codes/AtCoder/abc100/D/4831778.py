def main():
    N, M = [int(i) for i in input().split()]
    t = [[], [], [], [], [], [], [], []]
    for i in range(N):
        x, y, z = [int(i) for i in input().split()]
        for j in range(8):
            xs = 1 if j % 2 == 0 else -1
            ys = 1 if (j // 2) % 2 == 0 else -1
            zs = 1 if (j // 4) % 2 == 0 else -1
            t[j].append(xs * x + ys * y + zs * z) 
    res = []
    for li in t:
        li.sort(reverse=True)
        res.append(sum(li[:M]))
    print(max(res))

if __name__ == "__main__":
    main()