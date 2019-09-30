a = list(map(int, input().split()))
for i in range(2):
    a[2+2*i] -= a[0]
    a[2+2*i+1] -= a[1]
print(abs(a[2]*a[5]-a[3]*a[4])/2)