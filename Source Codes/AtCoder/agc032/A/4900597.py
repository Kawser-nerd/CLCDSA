_,s=open(0);a=['']
for i in s.split():a.insert(int(i)-1,i)
print(*a[-1]and[-1]or a)