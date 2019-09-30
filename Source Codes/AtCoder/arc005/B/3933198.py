x, y, W = map(str, input().split())
# ?????????????
x, y = int(x) - 1, int(y) - 1
inputs = [input() for _ in range(9)]

def cal_vector(vector1, vector2):
    return [vector1[0] + vector2[0], vector1[1] + vector2[1]]

def change_vector(x, y):
    global vector
    vector[0] = (-1) * vector[0] if x + vector[0]< 0 or x + vector[0] > 8 else vector[0]
    vector[1] = (-1) * vector[1] if y + vector[1] < 0 or y + vector[1] > 8 else vector[1]


vectors = {'R': [1, 0], 'L': [-1, 0], 'U': [0, -1], 'D': [0, 1]}
vectors.update(
    {
        'RU': cal_vector(vectors['R'], vectors['U']),
        'RD': cal_vector(vectors['R'], vectors['D']),
        'LU': cal_vector(vectors['L'], vectors['U']),
        'LD': cal_vector(vectors['L'], vectors['D'])
    }
)

vector = vectors[W]
ans = ''
for _ in range(4):
    ans += inputs[y][x]

    if x < 0 and y + vector[1] < 0:
        change_vector(x, y)

    elif x + vector[0] < 0 and y + vector[1] > 8:
        change_vector(x, y)

    elif x + vector[0] > 8 and y + vector[1] < 0:
        change_vector(x, y)
        
    elif x  + vector[0] > 8 and y + vector[1] > 8:
        change_vector(x, y)

    elif x  + vector[0] < 0:
        change_vector(x, y)

    elif x  + vector[0] > 8:
        change_vector(x, y)
        
    elif y + vector[1] < 0:
        change_vector(x, y)

    elif y + vector[1] > 8:
        change_vector(x, y)

    x += vector[0]
    y += vector[1]
        

print(ans)