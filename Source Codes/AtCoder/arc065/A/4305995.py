# coding: utf-8

def YESNO(ans, yes="YES", no="NO"):
    print([no, yes][ans])

II = lambda: int(input())
MI = lambda: map(int, input().split())
MIL = lambda: list(MI())
MIS = lambda: input().split()


def check(s):
    if s == "":
        return True
    if s[:5] in ["dream", "erase"]:
        return True
    return False


def main():
    S = input()
    i = 0
    l = len(S)
    while i < l:
        if S[i:i + 7] == "dreamer" and check(S[i + 7:]):
            i += 7
        elif S[i:i + 6] == "eraser" and check(S[i + 6:]):
            i += 6
        elif check(S[i:]):
            i += 5
        else:
            return False
    return True

if __name__ == "__main__":
    YESNO(main())