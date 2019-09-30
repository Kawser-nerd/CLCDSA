def plural(w: str)->str:
    return w + 's'


if __name__ == "__main__":
    w = input()
    ans = plural(w)
    print(ans)