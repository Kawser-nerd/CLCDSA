#!/usr/bin/python

def main():
    A, B = [int(x) for x in input().split()]
    print('Yay!') if A <= 8 and B <= 8 else print(':(')

if __name__ == '__main__':
    main()