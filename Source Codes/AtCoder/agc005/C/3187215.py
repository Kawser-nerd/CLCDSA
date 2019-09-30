n = int(input())
a = [int(i) for i in input().split()]
a.sort()
m,s = a[-1],a[0]
if m!=a[-2] or (m+1)//2!=s or (m%2 and s-a[1]) or ((not m%2) and s==a[1]) or any(a.count(i)<2 for i in range(s+1,m)) or (n!=2 and s==a[1]==a[2]): print("Impossible")
else: print("Possible")