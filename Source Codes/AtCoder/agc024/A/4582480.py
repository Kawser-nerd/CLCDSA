l = list(map(int,input().split()))
out = l[0]-l[1]
if out>10**18:
    print("Unfair")
elif l[3]%2==0:
    print(out)
else:
    print(out*(-1))