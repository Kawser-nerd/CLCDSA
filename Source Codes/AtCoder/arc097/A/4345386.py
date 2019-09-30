def solve(s, k):
    buff = []
    for start in range(len(s)):
        for end in range(1, k+1):
            if start + end > len(s):
                continue
            buff.append(s[start:start+end])
    buff = list(set(buff))
    buff.sort()
    return buff[k-1]

def main():
    s = input()
    k = int(input())
    ans = solve(s, k)
    print(ans)

if __name__ == "__main__":
    main()