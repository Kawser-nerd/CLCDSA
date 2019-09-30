ia,ib,ic,id=list(map(int, input().split()))
if ib/ia == id/ic:
    print("DRAW")
else:
    print("TAKAHASHI" if ib/ia > id/ic else "AOKI")