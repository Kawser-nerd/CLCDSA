import sys
data = filter(None, map(lambda x:x.strip(), open(sys.argv[1]).readlines()))

def pop_int(data):
    return int(data.pop(0))

def pop_ints(data):
    return map(int, data.pop(0).split())

def pop_rows(data, num_rows):
    result = data[:num_rows]
    for i in range(num_rows):
        data.pop(0)
    return result

def pop_case(data):
    return pop_ints(data)

def primes_between(low, high):
    global PRIMES_TO_1M
    return filter(lambda x: low <= x <= high, PRIMES_TO_1M)

def center_is_in(p1, p2, p3):
    x_sum = p1[0] + p2[0] + p3[0]
    if x_sum % 3:
        return False
    y_sum = p1[1] + p2[1] + p3[1]
    if y_sum % 3:
        return False
    return True

def solve(n, A, B, C, D, x0, y0, M):
    X = x0
    Y = y0
    points = [(x0, y0)]
    for i in range(1, n):
        X = (A * X + B) % M
        Y = (C * Y + D) % M
        points.append((X, Y))
    num_triangles = 0
    for i in range(len(points)):
        for j in range(i+1, len(points)):
            for k in range(j+1, len(points)):
                if center_is_in(points[i], points[j], points[k]):
                    num_triangles += 1
    return num_triangles


num_cases = pop_int(data)
for case_num in range(1, num_cases+1):
    answer = solve(*pop_case(data))
    print "Case #%d: %s" % (case_num, answer)
    





