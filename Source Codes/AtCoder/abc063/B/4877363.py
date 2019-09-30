import sys

def main():
    input = sys.stdin.readline
    S = input().strip()

    n = len(S)
    m = len(set(S))

    if n == m:
        return 'yes'
    else:
        return 'no'


if __name__ == '__main__':
    print(main())