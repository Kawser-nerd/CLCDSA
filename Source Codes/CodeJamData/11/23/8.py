def divide(n, walls):
    rooms = [range(n)]
    for a,b in walls:
        new = []
        for room in rooms:
            if a in room and b in room:
                x,y = sorted((room.index(a), room.index(b)))
                left, right = room[x:y+1], room[y:] + room[:x+1]
                new.append(left)
                new.append(right)
            else:
                new.append(room)
        rooms = new
    return rooms

def maximal(rooms):
    return min(map(len, rooms))
    
#def attempt(rooms, n):
#    root = 0
#    for i in range(len(rooms)):
#        if len(rooms[i]) < len(rooms[root]):
#            root = i
#    assigned2 = assigned[::]
#    for v in rooms[root]:
#        for 
 
def verify(rooms, function, c):
    return all(len(set(map(lambda v:function[v], room)))==c for room in rooms)
    
def functions(vertices, c):
    function = [0]*vertices
    yield function
    while any(f<c-1 for f in function):
        function[0]+=1
        carry = 0
        for i in range(vertices):
            function[i]+=carry
            carry = function[i]/c
            function[i] = function[i] % c
        yield function

def find(rooms, n, c):
    for function in functions(n, c):
        if verify(rooms, function, c):
            return function
    return False

def optimize(rooms, n):
    best = []
    for c in range(2, maximal(rooms)+1):
        new = find(rooms, n, c)
        if new:
            best = new
        else:
            return c-1, best
    return c, best
    
    
#rooms = divide(8, [(0,3), (0,6), (4,6)])

#print optimize(rooms, 8)

def main():
    cases = int(raw_input())
    for case in range(cases):
        n,m = map(int, raw_input().split(" "))
        walls_a = map(lambda s:int(s)-1, raw_input().split(" "))
        walls_b = map(lambda s:int(s)-1, raw_input().split(" "))
        walls = zip(walls_a, walls_b)
        rooms = divide(n, walls)
        c, best = optimize(rooms, n)
        #print best
        print "Case #%d: %d\n%s" % (case+1,  c, " ".join(map(lambda n:str(n+1), best)))

main()
