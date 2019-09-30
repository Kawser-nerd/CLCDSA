a=[int(input())for _ in[0]*int(input())]*2;b=c=m=0
for i in a:m=max(m,b+i,c+(i^1));b=-~b*i;c=-~c*(i^1)
print(-(len(set(a))<2)or~-m//2+1)