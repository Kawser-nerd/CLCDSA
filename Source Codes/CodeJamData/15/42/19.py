lines = open("b-large.txt").read().split("\n")
T = int(lines[0])

def f(N,X,V,lines2):
        sources = list(list(float(d) for d in line.split(' ')) for line in lines2)
    # if N==1:
    #     if sources[0][1]==X:
    #         return V/sources[0][0]
    #     else:
    #         return "IMPOSSIBLE"
    # elif N==2:
    #     if sources[0][1]==sources[1][1]:
    #         if sources[0][1]==X:
    #             return V/(sources[0][0]+sources[1][0])
    #         el se:
    #             return "IMPOSSIBLE"
    #     else:
    #         T1 = sources[0][1]
    #         T2 = sources[1][1]
    #         R1 = sources[0][0]
    #         R2 = sources[1][0]
    #         proportion_first = (X-T2)/(T1-T2)
    #         if proportion_first <0 or proportion_first > 1:
    #             return "IMPOSSIBLE"
    #         else:
    #             V1 = V*proportion_first
    #             V2 = V-V1
    #             return max(V1/R1,V2/R2)
    # else:
        rate = 0
        too_cold = []
        too_hot = []
        for source in sources:
            if source[1] > X:
                too_hot.append(source)
            elif source[1] < X:
                too_cold.append(source)
            else:
                rate += source[0]
        
        too_cold.sort(key=lambda s:s[1])
        too_hot.sort(key=lambda s:-s[1])
        cold_i = len(too_cold)-1
        hot_i = len(too_hot)-1
        # print rate,too_cold,too_hot
        
        while cold_i >= 0 and hot_i >= 0:
            cold = too_cold[cold_i]
            hot = too_hot[hot_i]
            
            if cold[0]*(X-cold[1]) > hot[0]*(hot[1]-X):
                rate += hot[0] + hot[0]*(hot[1]-X)/(X-cold[1])
                hot_i -= 1
                too_cold[cold_i][0] -= hot[0]*(hot[1]-X)/(X-cold[1])
            else:
                rate += cold[0] + cold[0]*(X-cold[1])/(hot[1]-X)
                cold_i -= 1
                too_hot[hot_i][0] -= cold[0]*(X-cold[1])/(hot[1]-X)
            # print rate,too_cold,too_hot
        if rate == 0:
            return "IMPOSSIBLE"
        else:
            return V/rate
curr_i = 1
for i in xrange(1,T+1):
    items = lines[curr_i].split(' ')
    N = int(items[0])
    X = float(items[2])
    V = float(items[1])
    # print X,V
    curr_i += 1
    out = f(N,X,V,lines[curr_i:curr_i+N])
    curr_i += N
    print "Case #%d: %s" % (i, out)