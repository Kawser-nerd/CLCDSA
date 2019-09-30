a=[int(input())for _ in[0]*int(input())]*2;m=c=0;f=2
for i in a:c=-~c*(f==i)or 1;m=max(m,c);f=i
print(-(len(set(a))<2)or~-m//2+1)