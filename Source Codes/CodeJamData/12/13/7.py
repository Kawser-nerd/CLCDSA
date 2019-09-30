#!/usr/bin/env python
from sys import argv
import copy

def find_collisions(cars):
    collisions = []
    for i in range(0, len(cars)):
        for j in range(0, len(cars)):
            c1 = cars[i]
            c2 = cars[j] 
            if c1["c"] == c2["c"]: # one line
                if c1["s"] > c2["s"]: #first faster
                    if c1["p"] < c2["p"]: #first behind
                        t_col = (c2["p"] - c1["p"] - 5) / (c1["s"] - c2["s"])
                        collisions.append((t_col, i, j))    
    return collisions

def update_cars(t, cars):
    for car in cars:
        car["p"] = car["p"] + car["s"] * t

def can_switch(c1, car):
    d = car["p"] - c1["p"]
    if abs(d) > 5:
        return True
    if abs(d) < 5:
        return False
    if d == -5:
        return (car["s"] <= c1["s"] )
    if d == 5:
        return (car["s"] >= c1["s"])
    
def can_avoid_cols(i, j, cars):
    c1 = cars[i]
    c2 = cars[j]
    can1 = True
    can2 = True
    for car in cars:
        #can first
        if car["c"] <> c1["c"]:
            can1 = can1 and can_switch(c1, car)
        #can second
        if car["c"] <> c2["c"]:
            can2 = can2 and can_switch(c2, car)
    return [can1, can2]
     
def get_time(t, cars):
    cols = find_collisions(cars)
    if len(cols) == 0:
        return "Possible"
    first_col = min(cols, key=lambda student: student[0])
    t_col = first_col[0]
    update_cars(t_col, cars)
    can1, can2 = can_avoid_cols(first_col[1], first_col[2], cars)
    if not (can1 or can2):
        return t + t_col
    else:
        t1 = 0
        t2 = 0
        if can1:
            cars1 = copy.deepcopy(cars)
            cars1[first_col[1]]["c"] = not cars1[first_col[1]]["c"]
            t1 = get_time(t + t_col, cars1)
        if can2:
            cars2 = copy.deepcopy(cars)
            cars2[first_col[2]]["c"] = not cars2[first_col[2]]["c"]
            t2 = get_time(t + t_col, cars2)
        if (t1 == "Possible") or (t2 == "Possible"):
            return "Possible"
        else:
            return max(t1, t2)
    
def solve(cars):
    return get_time(0, cars)

def read_case(lines):
    n = int(lines.pop(0))
    cars = []
    for i in range(0, n):
        line = lines.pop(0)
        c, s, p = line.split(" ")
        c = (c == "L")
        s = float(s)
        p = float(p)
        cars.append({"c": c,"s": s, "p": p})
    return (cars)

def result2str(i, result):
    s = "Case #" + str(i) + ": "
    s = s + str(result)
    # " ".join([str(i) for i in result])
    return s 
    
def main(in_filename, out_filename):
    with open(in_filename, 'r') as f:
        lines = f.readlines()

    n = int(lines.pop(0))
    output = []
    for i in range(1, n + 1):
        case = read_case(lines)
        result = solve(case)
        s = result2str(i, result)
        print s
        output.append(s + "\n")

    with open(out_filename, 'w') as f:
        f.writelines(output)
   
        
if __name__ == '__main__':
    main(argv[1], argv[2])