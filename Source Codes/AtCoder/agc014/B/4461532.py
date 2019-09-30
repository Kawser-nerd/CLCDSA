l=[0]*2**17
for i in open(0).read().split()[2:]:l[int(i)]+=1
print('YNEOS'[any(i%2for i in l)::2])