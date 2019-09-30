# MISC
read_int = lambda:int(raw_input().strip())
read_ints = lambda:[int(x) for x in raw_input().split()]
count_to = lambda n:xrange(1,n+1)

# GENERAL SOLVE LOOP
def solve_all(solve):
    num_cases = read_int()
    for i in count_to(num_cases):
         print "Case #{0}:".format(i),
         solve()

# SOLUTION
import math

def solve_case():
    l,p,c = read_ints()
    count=0
    while l*c < p:
        l*=c
        count+=1
    tests=0
    while count!=0:
        count>>=1
        tests+=1
    print tests

solve_all(solve_case)
