#!/usr/bin/env python3

def main():
    na, nb = map(int, input().split())
    an = set(map(int, input().split()))
    bn = set(map(int, input().split()))
    intersection = an & bn
    union = an | bn
    print(len(intersection) / len(union))

main()