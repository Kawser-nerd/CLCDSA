n = int(input())
s = 0
for i in range(1,int(n**0.5)+1):
    if n % i == 0:
        s += i + n//i
if (n**0.5).is_integer():
    s -= int(n**0.5)
if s > n*2:
    print("Abundant")
elif s < n*2:
    print("Deficient")
else:
    print("Perfect")