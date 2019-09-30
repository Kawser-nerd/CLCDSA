# coding: utf-8

def main():
    s = input().strip()
    if len(s) == 2:
        return ("1 2" if s[0] == s[1] else "-1 -1")
    for i in range(len(s) - 2):
        if len(set(s[i:i + 3])) <= 2:
            return "{} {}".format(i + 1, i + 3)
    return "-1 -1"


if __name__ == "__main__":
    print(main())