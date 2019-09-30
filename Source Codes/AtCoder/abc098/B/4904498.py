n=int(input())
ori=input()
max=0
for i in range(n-1):
    former=ori[:i+1]
    latter=ori[i+1:n]
    common=0
    for j in range(26):
        if chr(j+97) in former and chr(j+97) in latter:
            common+=1
        if max<=common:
            max=common
    
print(max)