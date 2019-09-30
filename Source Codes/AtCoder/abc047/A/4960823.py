i = sorted(list(map(int, input().split())), reverse= True)
print("Yes") if i[0]==i[1]+i[2] else print("No")