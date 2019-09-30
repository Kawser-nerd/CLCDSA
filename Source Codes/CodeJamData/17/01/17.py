#!/usr/bin/env python3

def flip(row):
    return row.translate(str.maketrans('-+', '+-'))

def solve(row, k):
    flips = 0
    for i in range(len(row)):
        if row[i] == '-' and i+k <= len(row):
            row = row[:i] + flip(row[i:i+k]) + row[i+k:]
            flips += 1
    if '-' in row:
        return "IMPOSSIBLE"
    else:
        return flips

def main():
    t = int(input())
    for ti in range(t):
        row, k = input().split(" ")
        print("Case #{}: {}".format(ti+1, solve(row, int(k))))

if __name__ == '__main__':
    main()
