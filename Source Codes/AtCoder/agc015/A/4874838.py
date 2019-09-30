N,A,B = map(int,input().split())
if A > B or B-A > N:
    print(0)
else:
    print(1+(N-2)*(B-A))