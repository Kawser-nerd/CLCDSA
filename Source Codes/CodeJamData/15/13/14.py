# python A.py < A-small-attempt0.in > A-small-attempt0.out
# 
# list(raw_input()) # List of chars
# [int(n) for n in raw_input().split()] # List of ints

from math import atan, pi

if __name__ == "__main__":
    testcases = input()
    
    for case in xrange(1, testcases+1):
        
        num_trees = int(raw_input())
        trees = [[int(n) for n in raw_input().split()] for _ in range(num_trees)]

        print("Case #%i:" % (case))
        for i in range(num_trees):
            r_angles, l_angles = [], []
            for j in range(num_trees):
                if j == i:
                    continue
                d_x, d_y = trees[j][0] - trees[i][0], trees[j][1] - trees[i][1]
                if d_x > 0:
                    r_angles.append(atan(float(d_y) / float(d_x)))
                elif d_x < 0:
                    l_angles.append(atan(float(d_y) / float(d_x)))
                elif d_y < 0:
                    l_angles.append(pi)
                else:
                    r_angles.append(pi)
            r_angles = sorted(r_angles)
            l_angles = sorted(l_angles)
            n_r, n_l = len(r_angles), len(l_angles)
            min_r, min_l = n_r, n_l
            while len(r_angles) > 0 or len(l_angles) > 0:
                if len(r_angles) > 0 and len(l_angles) > 0:
                    next_val = min(r_angles[0], l_angles[0])
                elif len(r_angles) > 0:
                    next_val = r_angles[0]
                else:
                    next_val = l_angles[0]
                from_r, from_l = 0, 0
                while r_angles and r_angles[0] == next_val:
                    r_angles.pop(0)
                    from_r += 1
                while l_angles and l_angles[0] == next_val:
                    l_angles.pop(0)
                    from_l += 1
                n_r -= from_r
                n_l -= from_l
                min_r = min(min_r, n_r)
                min_l = min(min_l, n_l)
                n_r += from_l
                n_l += from_r
            print min(min_r, min_l)
