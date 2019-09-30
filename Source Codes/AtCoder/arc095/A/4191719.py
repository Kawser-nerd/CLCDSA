def solve(N, Xs):
    sorted_Xs = sorted(Xs)
    left = sorted_Xs[N // 2 - 1]
    right = sorted_Xs[N // 2]
    ans = []
    for x in Xs:
        if x <= left:
            ans.append(right)
        else:
            ans.append(left)
    return "\n".join(str(i) for i in ans)

if __name__ == "__main__":
    N = int(input())
    Xs = list(map(int, input().split(" ")))
    print(solve(N, Xs))