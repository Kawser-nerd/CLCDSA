def solve(s):
    sums = 0
    sumt = 0
    ans = 0
    for i in s:
        if i == 'S':
            sums += 1
        else:
            if sums > 0:
                sums -= 1
                ans += 2
    return len(s)-ans

if __name__ == '__main__':
    s = input()
    print(solve(s))