import sys

def main():
    input = sys.stdin.readline
    a, b = map(str, input().split())

    if a == 'H':
        return b
    else:
        if b == 'H':
            return 'D'
        else:
            return 'H'


if __name__ == '__main__':
    print(main())