n=int(input())
if n%10<7:print((round(n//10)*100)+((n%10)*15))
else:print(100*(round(n//10)+1))