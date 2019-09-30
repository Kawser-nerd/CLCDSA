def index(s: str, idx: int)->str:
    return s[idx-1]


if __name__ == "__main__":
    s = input()
    idx = int(input())
    ans = index(s, idx)
    print(ans)