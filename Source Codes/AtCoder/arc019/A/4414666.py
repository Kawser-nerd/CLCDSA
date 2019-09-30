k=[]

p = list(input())

for i in range(len(p)):
    if p[i] == "O" or p[i] == "D":p[i] = "0"
    elif p[i] == "I":p[i] = "1"
    elif p[i] == "Z":p[i] = "2"
    elif p[i] == "S":p[i] = "5"
    elif p[i] == "B":p[i] = "8"
print(''.join(p))