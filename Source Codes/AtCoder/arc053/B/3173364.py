from collections import Counter
s = input()
ds =Counter(s)
odd = even = 0
for i in ds.values():
    if i%2!=0:
        odd+=1
    else:
        even+=i
if odd<2:
    print(len(s))
else:
    print((len(s)-odd)//2//odd*2+1)