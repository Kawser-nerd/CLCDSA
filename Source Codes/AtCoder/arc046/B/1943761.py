N = int(input())
A,B = map(int,input().split())

def judge():
    if A == B:
        return 1 if N%(A+1) != 0 else 0
    if A > B:
        return 1
    return 1 if N <= A else 0

print('Takahashi' if judge() else 'Aoki')