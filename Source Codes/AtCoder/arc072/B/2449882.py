import collections


def solve():
    x,y = map(int,input().split())
    if x-y == 0 or abs(x-y) == 1:
        print("Brown")
    else:
        print("Alice")

if __name__ == "__main__":
    solve()