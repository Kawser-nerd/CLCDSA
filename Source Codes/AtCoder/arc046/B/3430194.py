N = int(input())
A, B = map(int, input().split())
if A == B:
    print("Takahashi" if N % (A+1) > 0 else "Aoki")
else:
    print("Takahashi" if N <= A or A > B else "Aoki")