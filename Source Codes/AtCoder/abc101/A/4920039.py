#!/usr/bin/python

def main():
    chars = list(input())
    n = 0
    for c in chars:
        n = n+1 if c == '+' else n-1
    print(n)

if __name__ == '__main__':
    main()