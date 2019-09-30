s = input()
K = int(input())

for i in range(len(s)) :
    if i == K - 1 :
        print(s[i])
        break
    
    if s[i] == '1' :
        continue
    else :
        print(s[i])
        break