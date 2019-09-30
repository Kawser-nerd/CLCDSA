#!/usr/bin/env python3

def main():
    l = int(input())
    bl = [int(input()) for i in range(l)]
    al = [0]
    for i in range(1, l):
        al.append(al[i - 1] ^ bl[i - 1])
    if al[-1] == bl[-1]:
        for i in range(l):
            print(al[i])
    else:
        print(-1)

main()