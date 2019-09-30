import time, sys
from random import random
from math import sqrt

# is the space empty on that side of the given square?
def freehoriz(maptext, x, y, dx, W):
    return 0 <= x + dx < W and maptext[y][x+dx] in '.X'
def freevert(maptext, x, y, dy, H):
    return 0 <= y + dy < H and maptext[y+dy][x] in '.X'

# returns not exactly the locations of mirror surfaces
# but rather horizontal and vertical (co)ordinates where
# a mirror is found somewhere along that line
def getmirrors(maptext, W, H):
    mirrors = set()
    for my in range(H):
        for mx in range(W):
            if maptext[my][mx] == '#':
                for (dx, side) in ((-1, 0), (1, 1)):
                    if freehoriz(maptext, mx, my, dx, W):
                        mirrors.add(('horiz', 2*(mx + side)))
                for (dy, side) in ((-1, 0), (1, 1)):
                    if freehoriz(maptext, mx, my, dy, W):
                        mirrors.add(('vert', 2*(my + side)))
    return mirrors

def getviewpoint(maptext, W, H):
    for my in range(H):
        for mx in range(W):
            if maptext[my][mx] == 'X':
                return (2*mx + 1, 2*my + 1)

def distance2(a, b):
    (ax, ay) = a
    (bx, by) = b
    return (ax - bx)**2 + (ay - by)**2

def sgn(x):
    if x == 0:
        return 0
    elif x > 0:
        return 1
    else:
        return -1

# greatest common divisor
def gcd(a, b):
    if b == 0:
        return a
    elif a == 0:
        return b
    elif a == 1 or b == 1:
        return 1
    return gcd(b, a % b)

graphics = False

# return the distance squared from the viewpoint
# to the image seen in the given direction (dx, dy)
# or None if we can't see an image
def look(maptext, dx, dy, vx, vy, D2):
    (adx, ady) =(abs(dx), abs(dy))
    if dx == 0:
        units = abs(dy)
    elif dy == 0:
        units = abs(dx)
    else:
        units = abs(dx * dy)
    t = 0
    (uvx, uvy) = (vx * units, vy * units)
    (ux, uy) = (uvx, uvy)

    if graphics:
        path = []

    while True:
        if graphics:
            path.append((ux, uy))

        # find out how far we have to go to hit the next object of interest
        dt = 'infinity'
        for (o, xy) in mirrors:
            uxy = units * xy
            if o == 'horiz' and (uxy - ux)*dx > 0:
                dt = min(dt, (uxy - ux)//dx)
            elif o == 'vert' and (uxy - uy)*dy > 0:
                dt = min(dt, (uxy - uy)//dy)
        if (uvx - ux)*dx > 0:
            dt = min(dt, (uvx - ux)//dx)
        if (uvy - uy)*dy > 0:
            dt = min(dt, (uvy - uy)//dy)

        # dt = 'infinity'
        # if dx > 0:
        #     dt = min(dt, (units - ux % units) // adx)
        # elif dx < 0:
        #     dt = min(dt, (ux % units or units) // adx)
        # if dy > 0:
        #     dt = min(dt, (units - uy % units) // ady)
        # elif dy < 0:
        #     dt = min(dt, (uy % units or units) // ady)

        t += dt
        ux += dt * dx
        uy += dt * dy

        (x, y) = (ux // units, uy // units)
        # print (x, y), (ux, uy)

        if (t*t * (dx*dx + dy*dy)) > D2 * units**2:
            # gone into the fog
            return None

        if graphics:
            screen.fill((0, 0, 0))
            scale = min(1200.0 / W, 700.0 / H)
            uscale = scale / (2 * units)
            drawmap(screen, scale, maptext, H, W)
            draw.aalines(screen, (255, 0, 0), False, [(int(px * uscale), int(py * uscale)) for (px, py) in path + [(ux, uy)]])
            pygame.display.flip()

        if ux % units == 0 and uy % units == 0:
            # at a corner or center of square
            if (x % 2 == 1) and (y % 2 == 1):
                # center of a square
                if (x, y) == viewpoint:
                    # we can see ourself!
                    if graphics:
                        draw.aalines(screen, (255, 0, 255), False, [(int(px * uscale), int(py * uscale)) for (px, py) in path + [(ux, uy)]])
                        pygame.display.flip()
                        # gfxdraw.pixel(screen, int(ux * uscale), int(uy * uscale), (255, 255, 255))
                    return (t*t * (dx*dx + dy*dy)) // (units*units)

            elif (x % 2 == 0) and (y % 2 == 0):
                # corner
                # find the square we're entering
                (cx, cy) = ((x + sgn(dx)) // 2, (y + sgn(dy)) // 2)
                if maptext[cy][cx] == '#':
                    # hit a mirror
                    # need to find out whether we hit a protruding corner, or something else
                    (xhx, xhy) = ((x - sgn(dx)) // 2, (y + sgn(dy)) // 2)
                    # gfxdraw.pixel(screen, (x - sgn(dx))*units//4, (y + sgn(dy))*units//4, (0, 255, 255))
                    (yhx, yhy) = ((x + sgn(dx)) // 2, (y - sgn(dy)) // 2)
                    # gfxdraw.pixel(screen, (x + sgn(dx))*units//4, (y - sgn(dy))*units//4, (255, 255, 0))
                    if maptext[xhy][xhx] == '#':
                        # there's another mirror along the corner horizontally, so we get reflected vertically
                        dy = -dy
                    if maptext[yhy][yhx] == '#':
                        # there's another mirror along the corner vertically, so we get reflected horizontally
                        dx = -dx
                    if maptext[xhy][xhx] != '#' and maptext[yhy][yhx] != '#':
                        # protruding corner, we die
                        if graphics:
                            draw.aalines(screen, (0, 255, 255), False, [(int(px * uscale), int(py * uscale)) for (px, py) in path + [(ux, uy)]])
                            pygame.display.flip()
                        return None
                    # if both of these cases are true, we get reflected straight back
                continue

        if ux % units == 0 and x % 2 == 0:
            # somewhere along an edge of a square
            # find the square we're entering
            (cx, cy) = ((x + sgn(dx)) // 2, y // 2)
            if maptext[cy][cx] == '#':
                # a vertical mirror
                dx = -dx
        elif uy % units == 0 and y % 2 == 0:
            # somewhere along an edge of a square
            # find the square we're entering
            (cx, cy) = (x // 2, (y + sgn(dy)) // 2)
            if maptext[cy][cx] == '#':
                # a horizontal mirror
                dy = -dy


def drawmap(screen, scale, maptext, H, W):
    for y in range(H):
        for x in range(W):
            if maptext[y][x] == '#':
                gfxdraw.line(screen, int(x * scale), int(y * scale), int((x+1)*scale), int(y * scale), (0, 255, 0))
                gfxdraw.line(screen, int(x * scale), int(y * scale), int(x*scale), int((y+1) * scale), (0, 255, 0))
                gfxdraw.line(screen, int((x+1) * scale), int((y+1) * scale), int((x+1)*scale), int(y * scale), (0, 255, 0))
                gfxdraw.line(screen, int((x+1) * scale), int((y+1) * scale), int(x*scale), int((y+1) * scale), (0, 255, 0))

if graphics:
    # graphical output for debugging
    import pygame
    from pygame import gfxdraw, draw
    pygame.init()
    screen = pygame.display.set_mode((1200, 700), 0, 32)

data = open('D-large.in', 'r')
T = int(data.readline().strip())
for case in range(1, T+1):
    skip = False
    (H, W, D) = tuple(map(int, data.readline().split()))
    # doubling the scale to keep everything integral
    D = 2 * D
    maptext = [data.readline().strip() for y in range(H)]

    # for y in range(H):
    #     maptext[y] = list(maptext[y])
    #     for x in range(W):
    #         if maptext[y][x] == '.' and random() < 0.4:
    #             maptext[y][x] = '#'

    mirrors = getmirrors(maptext, W, H)
    viewpoint = getviewpoint(maptext, W, H)
    (vx, vy) = viewpoint

    directions = set()
    for dy in range(-D, D+1):
        for dx in range(-D, D+1):
            if dx*dx + dy*dy > D**2:
                continue
            directions.add((dx, dy))
    
    directions.discard((0, 0))
    directions = set((dx / abs(gcd(dx, dy)), dy / abs(gcd(dx, dy))) for (dx, dy) in directions)
    
    # index = 0
    count = 0
    for (dx, dy) in directions:
        # index += 1
        # sys.stdout.write('{} / {}    \r'.format(index, len(directions)))
        # sys.stdout.flush()
        l = look(maptext, dx, dy, vx, vy, D*D)
        if l:
            count += 1
        # print (dx, dy)
        if graphics:
            wait = True
            while wait and not skip:
                for event in pygame.event.get():
                    if event.type == pygame.KEYDOWN:
                        wait = False
                        if event.unicode == '.':
                            skip = True
                        break

    print 'Case #{}: {}'.format(case, count)
    sys.stdout.flush()

exit()
