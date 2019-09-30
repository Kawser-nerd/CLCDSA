A,B = map(int,input().split())
S = input().strip()

if "-" not in S or len(S.split("-")) > 2:
    print("No")
    exit()

left,right = S.split("-")

if len(left) == A and len(right) == B:
    print("Yes")
else:
    print("No")