heihousuu = [i*i for i in range(int(100100**0.5))]

a,b= input().split()
ab = int(a+b)

print('Yes' if ab in heihousuu else 'No')