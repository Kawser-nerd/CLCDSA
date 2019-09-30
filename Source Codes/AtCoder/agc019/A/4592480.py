q,h,s,d = map(int,input().split())
n = int(input())
a = [q*8,h*4,s*2,d]
min_s = min(a[:3]) // 2
min_d = min(a)
b,c = divmod(n,2)
print(b*min_d + c * min_s)