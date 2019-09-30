s=[['.']*100 for i in range(50)]+[['#']*100 for i in range(50)]
a,b=map(int, input().split())
a-=1
b-=1
a1,a2=a%50,a//50
b1,b2=b%50,b//50
for i in range(b2):
    for j in range(50):s[i*2][j*2]='#'
for j in range(b1):s[48][j*2]='#'
for i in range(a2):
    for j in range(50):s[51+i*2][j*2]='.'
for j in range(a1):s[98][j*2]='.'
print(100,100)
for i in s:print(''.join(i))