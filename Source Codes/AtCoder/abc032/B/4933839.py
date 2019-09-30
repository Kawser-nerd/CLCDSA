s = input()
n = int(input())

s_list = list(s)
aaa = []
for i in range(len(s)-n+1):
    temp = ''.join(s_list[i:i+n])
    aaa.append(temp)
    
print(len(set(aaa)))