H,W = map(int,input().split())
src = [input() for i in range(H)]

mem = [[None for j in range(W)] for i in range(H)]
def win(x,y):
    if x >= W or y >= H or src[y][x] == '#':
        return True
    if mem[y][x] is not None:
        return mem[y][x]
    result = False
    if not win(x,y+1): result = True
    if not win(x+1,y+1): result = True
    if not win(x+1,y): result = True
    mem[y][x] = result
    return result

print('First' if win(0,0) else 'Second')