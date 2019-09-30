n=int(input())
lr=[[int(i) for i in input().split()] for _ in range(n)]
persona=0
for i in range(n):
    persona+=lr[i][1]-lr[i][0]+1
print(persona)