import sys
MOD = 10 ** 9+7
input = sys.stdin.readline
def ii(): return int(input())
def mi(): return map(int, input().rstrip().split())
def lmi(): return list(map(int, input().rstrip().split()))
def li(): return list(input().rstrip())
# template


X, t = mi()
print(max(X-t,0))