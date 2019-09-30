#!/usr/bin/python

def main():
    A = [int(x) for x in input().split()]
    print(max(A)-min(A))

if __name__ == '__main__':
    main()