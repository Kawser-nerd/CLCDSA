from operator import itemgetter
from math import sqrt
x1,y1,x2,y2,x3,y3 = map(int, input().split())
xy = [(x1, y1), (x2, y2), (x3, y3)]

# ??????
def edge_len(x1,y1,x2,y2):
    return sqrt((x1-x2)**2 + (y1-y2)**2)

ls = [edge_len(x1,y1,x2,y2), edge_len(x1,y1,x3,y3), edge_len(x2,y2,x3,y3)]
s = sum(ls)/2
print(sqrt(s*(s-ls[0])*(s-ls[1])*(s-ls[2])))