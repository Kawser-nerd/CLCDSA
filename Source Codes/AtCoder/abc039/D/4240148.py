def seek_ink(x, y):
    for i in range(-1, 2):
        for j in range(-1, 2):
            if(current_map[max(min(H - 1, y + i), 0)][max(min(W - 1, x + j), 0)] == "."):
                return "."
    return "#"

def drop_ink(x, y):
    for i in range(-1, 2):
        for j in range(-1, 2):
            if(past_map[max(min(H - 1, y + i), 0)][max(min(W - 1, x + j), 0)] == "#"):
                return "#"
    return "."

def go_back():
    past_map = dict()
    for h in range(H):
        past_map[h] = dict()
        for w in range(W):
            past_map[h][w] = seek_ink(w, h)
    return past_map

def re_drop():
    new_map = dict()
    for h in range(H):
        new_map[h] = dict()
        for w in range(W):
            new_map[h][w] = drop_ink(w, h)
    return new_map

H, W = [int(x) for x in input().strip().split()]
current_map = dict()
for h in range(H):
    current_map[h] = dict()
    row = input().strip()
    for w in range(W):
        current_map[h][w] = row[w]

past_map = go_back()
new_map = re_drop()

if(new_map == current_map):
    print("possible")
    for h in range(H):
        line = ""
        for w in range(W):
            line += past_map[h][w]
        print(line)
else:
    print("impossible")