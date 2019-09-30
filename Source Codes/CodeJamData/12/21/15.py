import sys
import bisect

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    line = [int(x) for x in f.readline().split()]
    (N, s) = line[0], line[1:]

    total_points = sum(s)
    temp = s[:]
    temp.sort()
    while total_points > 0:
        val = temp.pop(0)

        count = 1
        while temp and val == temp[0]:
            temp.pop(0)
            count += 1            

        if total_points >= count:
            val += 1
            total_points -= count
        else:
            val += float(total_points) / count
            total_points = 0
            
        for i in range(0, count):
            bisect.insort(temp, val)

    needed = temp[0]

    total_points = sum(s)
    for i in range(0, len(s)):
        s[i] = max(0, 100 * float(needed - s[i]) / total_points) 
    formatted_values = " ".join(["%6f" % value for value in s])

    print "Case #%d: %s" % (case + 1, formatted_values)
