a,b = map(str,input().split())
ab = int(a+b)
hei = [i*i for i in range(1,1000)]
print('Yes' if ab in hei else 'No')