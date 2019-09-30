# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

def main():
    N, A, B, C, D = map(int, input().split())

    for i in range(1,N):
        if C*(N-1-i) - D*i <= B - A <= D*(N-1-i) - C*i:
            print("YES")
            return

    print("NO")

if __name__ == '__main__':
    main()