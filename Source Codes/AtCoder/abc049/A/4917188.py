import sys, os

f = lambda:list(map(int,input().split()))
def init():
    if 'local' in os.environ :
        sys.stdin = open('./input.txt', 'r')

def solve():
    a = input()
    if a in ['a', 'e', 'i', 'o', 'u']:
        print("vowel")
    else:
        print("consonant")

init()
solve()