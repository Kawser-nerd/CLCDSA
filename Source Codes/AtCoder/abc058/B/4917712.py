import sys

def main():
    input = sys.stdin.readline
    O = str(input().strip())
    E = str(input().strip())

    ans = ''
    for i in range(len(O)):
        if i == len(O) - 1 and len(O) != len(E):
            ans += O[i]

        else:
            ans += O[i]
            ans += E[i]

    return ans


if __name__ == '__main__':
    print(main())