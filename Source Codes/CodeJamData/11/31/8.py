import sys

t = int(sys.stdin.readline())

def paint(picture, r, c):
    for y in range(r):
        for x in range(c):
            if picture[y][x] == '#' and picture[y][x+1] == '#' \
                    and picture[y+1][x] == '#' and picture[y+1][x+1] == '#':
                        picture[y][x] = picture[y+1][x+1] = '/'
                        picture[y][x+1] = picture[y+1][x] = '\\'
    for y in picture:
        if '#' in y:
            return False
    return True

def print_picture(picture, r, c):
    for i in range(r):
        print ''.join(picture[i][:c])

for i in range(t):
    print "Case #%d:" % (i+1)
    r, c = map(int, sys.stdin.readline().split())
    picture = []
    for j in range(r):
        picture.append(list(sys.stdin.readline().strip()+'.....'))
    picture.append((c+5) * ['.'])
    if paint(picture,r,c):
        print_picture(picture, r, c)
    else:
        print "Impossible"


