def password(s: str, k: int)->int:
    t = set()
    for i in range(len(s)-k+1):
        t.add(s[i:i+k])
    return len(t)


if __name__ == "__main__":
    s = input()
    k = int(input())
    ans = password(s, k)
    print(ans)