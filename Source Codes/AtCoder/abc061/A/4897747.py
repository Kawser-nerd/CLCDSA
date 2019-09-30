import sys

def main():
    input = sys.stdin.readline
    A = list(map(int, input().split()))

    if A[0] <= A[2] <= A[1]:
        return 'Yes'
    else:
        return 'No'


if __name__ == '__main__':
    print(main())