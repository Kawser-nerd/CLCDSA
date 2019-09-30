s=input()
d=[0]*26
for i in s:
    d[ord(i)-ord("a")]+=1
k=[i%2 for i in d].count(1)
print(2*((len(s)-k)//(2*k))+1 if k>0 else len(s))