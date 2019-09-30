import itertools
from collections import Counter
import bisect

def main():
    s = list(input())
    s = list(set(s))
    s.sort()
    cur = ord('a')
    # print(s)
    for c in s:
        if cur == ord(c):
            cur = cur + 1
        else:
            print(chr(cur))
            exit()
    if cur == ord('z') + 1:
        print('None')
    else:
        print(chr(cur))

if __name__ == '__main__':
    main()