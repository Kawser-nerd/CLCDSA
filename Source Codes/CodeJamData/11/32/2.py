T = int(raw_input())

for n in range(T):
    line = map(int, raw_input().split(' '))
    L,t,N = line[:3]
    Cs = line[4:]
    Cs *= (N//len(Cs))+1
    Cs = Cs[:N]

    time = 0
    pos = 0

    if L:
        while pos < N:
            if time + Cs[pos]*2 <= t:
                time += Cs[pos]*2
                pos += 1
            elif time == t:
                time += sum(sorted(Cs[pos:])[-L:])
                time += 2*sum(sorted(Cs[pos:])[:-L])
                break
            else:
                # hypothesis, do we build or not?
                gain = ( (Cs[pos]*2) - (t - time) ) / 2
                if L > 1:
                    gain += sum(sorted(Cs[pos+1:])[-L+1:])

                other_gain = sum(sorted(Cs[pos+1:])[-L:])

                time+= sum(Cs[pos:])*2 - max(gain, other_gain)
                break
    else:
        time = sum(Cs)*2


    print "Case #%d: " %(n+1), time
