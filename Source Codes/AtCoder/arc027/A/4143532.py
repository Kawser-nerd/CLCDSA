h,m = map(int,input().split())

def get_minute(in_h,in_m) :
    return in_h*60 + in_m

ans = get_minute(18,0) - get_minute(h,m)

print(ans)