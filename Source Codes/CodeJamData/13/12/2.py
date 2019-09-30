def readline():
    return [int(x) for x in raw_input().split(' ')]

def maxi(l, left, right):
    m=l[left]
    mi=left
    for i in range(left, right):
        if l[i]>m:
            mi=i
            m=l[i]
    return mi
    

cases = readline()[0]

for v in range(cases):
    E,R,N=readline()
    if R>E: R=E
    tasks = readline()

    def solve(left, right, se, ee):
        #print (left, right, se, ee)
        if right == left: return 0
        if right - left == 1:
            me = ee - R
            if me < 0: assert False
            return tasks[left]*(se - me)
        split = maxi(tasks, left, right)
        newee = min(se + (split - left) * R, E)
        newse = max(ee - (right - split - 1) * R, R)
        k = newee-newse+R
        return solve(left, split, se, newee) + solve(split+1, right, newse, ee) + k * tasks[split]
    ans = solve(0, len(tasks), E, R)
    print "Case #%d: %d"%(v+1, ans)
