n=int(input())
if 0<n%10<7:print(100*(n//10)+15*(n%10))
else:print(100*(((n-1)//10)+1))