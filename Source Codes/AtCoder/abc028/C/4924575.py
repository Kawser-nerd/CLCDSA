def select3(A: int, B: int, C: int, D: int, E: int) -> int:
    l = [A, B, C, D, E]
    res = []

    for i in range(1 << 5):
        s, c = 0, 0
        for j in range(5):
            if i & (1 << j) == 0:
                continue
            s += l[j]
            c += 1
        if c != 3:
            continue
        res.append(s)

    return sorted(res, key=lambda x: - x)[2]


if __name__ == "__main__":
    A, B, C, D, E = map(int, input().split())
    ans = select3(A, B, C, D, E)
    print(ans)