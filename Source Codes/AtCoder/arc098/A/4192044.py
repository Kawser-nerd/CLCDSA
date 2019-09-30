from collections import Counter


def solve(N, S):
    c = Counter(S)
    ans = 3 * 10 ** 5 + 1

    right_e = c["E"]
    left_w = 0
    for i in range(N):
        if S[i] == "E":
            right_e -= 1

        ans = min(ans, left_w + right_e)

        if S[i] == "W":
            left_w += 1
    return ans


if __name__ == "__main__":
    N = int(input())
    S = input()
    print(solve(N, S))