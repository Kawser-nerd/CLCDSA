import sys

def main():
    input = sys.stdin.readline
    x, y = map(int, input().split())

    a = [1, 3, 5, 7, 8, 10, 12]
    b = [4, 6, 9, 11]
    c = [2]

    if x in a and y in a:
        return 'Yes'
    elif x in b and y in b:
        return 'Yes'
    elif x in c and y in c:
        return 'Yes'
    else:
        return 'No'


if __name__ == '__main__':
    print(main())