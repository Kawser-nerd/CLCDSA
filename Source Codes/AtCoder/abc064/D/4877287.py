import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    S = input().strip()
    
    L = ''
    R = ''
    c = 0
    for s in S:
        if s == '(':
            c += 1
        else:
            c -= 1

        if c < 0:
            L += '('
            c += 1

    R += ')' * c

    return L + S + R


if __name__ == '__main__':
    print(main())