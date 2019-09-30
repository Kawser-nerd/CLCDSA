n  =  int(input())
a  =  list(map(int, input().split()))
a.sort(reverse = True)
d  =  {}
count = 0

for x in a:
    if x not in d: d[x] = 0
    d[x] += 1
    
for i in range(len(a)):
    if d[a[i]] == 0:continue
        
    d[a[i]] -= 1
    
    y = 2**a[i].bit_length() - a[i]
    
    if y in d and d[y] > 0:
        count += 1
        d[y]  -= 1
        
print(count)