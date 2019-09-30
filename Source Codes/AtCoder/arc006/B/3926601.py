n,l = map(int,input().split())
a = [list(input()) for i in range(l)]
goal = input().find('o')
s = [l-1,goal]

def amida(x,y):
    if x == -1:
        return y//2+1
    
    if y-1 >= 0 and a[x][y-1] == '-':
        return amida(x-1, y-2)
    elif y+1 <= 2*n -2 and a[x][y+1] == '-':
        return amida(x-1, y+2)
    else:
        return amida(x-1, y)

print(amida(s[0], s[1]))