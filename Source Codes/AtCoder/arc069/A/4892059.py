S,C=map(int,input().split(' '))
print(min(S,C//2)+(C-min(S,C//2)*2)//4)