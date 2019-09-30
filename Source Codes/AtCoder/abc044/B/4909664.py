import collections
letter=collections.Counter(input())
counter=0
for v in letter.values():
    if v%2==1:
        counter +=1
        break
print("Yes") if counter==0 else print("No")