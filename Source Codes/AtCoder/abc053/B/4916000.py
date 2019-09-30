s = str(input())
count = 1
for i in s:
    if i == "A":
        A_index = count
        break
    count += 1
    
count = 1
for i in list(reversed(s)):
    if i == "Z":
        Z_index = count
        break
    count += 1
    
print(len(s)-A_index-Z_index+2)