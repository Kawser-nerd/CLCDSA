s = int(input())
i = 0
if(s//100==1):
    i = i + 1
    s = s - 100
if(s//10==1):
    i = i + 1
    s = s-10
if(s==1):
    i = i + 1
print(i)