s=input()
count=0
count_list=[]
seq=["A","T","G","C"]
for base in s:
    if base in seq:
        count +=1
    else:
        count_list.append(count)
        count = 0
    count_list.append(count)
print(max(count_list))