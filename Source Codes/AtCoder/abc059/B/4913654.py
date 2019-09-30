import sys

def main():
    input = sys.stdin.readline
    A = int(input())
    B = int(input())

    if A == B:
        return 'EQUAL'
    elif A > B:
        return 'GREATER'
    else:
        return 'LESS'


if __name__ == '__main__':
    print(main())