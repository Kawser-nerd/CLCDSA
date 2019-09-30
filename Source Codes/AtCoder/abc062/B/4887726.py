import sys

def main():
    input = sys.stdin.readline
    H, W = map(int, input().split())

    ud = '#' * (W+2)
    print(ud)
    for _ in range(H):
        a = input().strip()
        print('#' + a + '#')
    print(ud)


if __name__ == '__main__':
    main()