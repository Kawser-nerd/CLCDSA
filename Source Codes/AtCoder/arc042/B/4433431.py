import numpy


x, y = map(int, input().split())
N = int(input())
inputs = [list(map(int, input().split())) for _ in range(N)]

inputs.append(inputs[0])

def cal(x1, y1, x2, y2):
    global x, y

    u = numpy.array([x2 - x1, y2 - y1])
    v = numpy.array([x - x1, y - y1])
    L = abs(numpy.cross(u, v) / numpy.linalg.norm(u))
    
    return L

print(min([cal(item1[0], item1[1], item2[0], item2[1]) for item1, item2 in zip(inputs, inputs[1:])]))