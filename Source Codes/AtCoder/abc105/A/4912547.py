#!/usr/bin/python

def main():
    A, B = [int(x) for x in input().split()]
    print(0) if A%B==0 else print(1)

if __name__ == '__main__':
    main()