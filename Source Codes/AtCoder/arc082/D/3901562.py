input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())
 
# f(a) = z                 a <= x1
#        a+z-x1      x1 <= a <= x2
#        x2+z-x1     x2 <= a
class Sandgraph:
    def __init__(_, X):
        _.z = _.x1 = 0
        _.x2 = X
    
    def add(_, dt):
        # Go towards the ceiling
        d1 = min(dt, X-(_.x2+_.z-_.x1))
        _.z+= d1
        dt-= d1
        # Reduce the diagonal
        d1 = min(dt, _.x2-_.x1)
        _.z+= d1
        _.x2-= d1
    
    def sub(_, dt):
        # Go towards the floor
        d1 = min(dt, _.z)
        _.z-= d1
        dt-= d1
        # Reduce the diagonal
        d1 = min(dt, _.x2-_.x1)
        _.x1+= d1
    
    def __call__(_, a):
        if a <= _.x1: return _.z
        elif a <= _.x2: return a + _.z - _.x1
        else: return _.x2 + _.z - _.x1
 
X = int(input())
k = int(input())
rev = list(MIS())
Q = int(input())
sand = Sandgraph(X)
 
last_t = 0
i = 0 # even -, odd +
for QUERY in range(Q):
    t, a = MIS()
    while i<k and rev[i] <= t:
        dt = rev[i] - last_t
        if i%2 == 0: sand.sub(dt)
        else: sand.add(dt)
        last_t = rev[i]
        i+= 1
    dt = t - last_t
    if i%2 == 0: sand.sub(dt)
    else: sand.add(dt)
    print(sand(a))
    last_t = t