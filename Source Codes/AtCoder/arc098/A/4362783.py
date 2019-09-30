def solve(string):
    # 1-origin
    length = len(string)
    east, west = [0] * (length + 1), [0] * (length + 2)

    for i in range(1, length + 1):
        if string[i - 1] == "W":
            east[i] = east[i - 1] + 1
        else:
            east[i] = east[i - 1]
    for j in range(length, 0, -1):
        if string[j - 1] == "E":
            west[j] = west[j + 1] + 1
        else:
            west[j] = west[j + 1]

    ans = length
    for k in range(1, length + 1):
        ans = min(ans, east[k - 1] + west[k + 1])
    return ans


def main():
    n = int(input())
    string = input()
    ans = solve(string)
    print(ans)


main()