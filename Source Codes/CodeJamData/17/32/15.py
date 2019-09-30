with open('B-large.in') as infile:
    with open('B-large.out', 'w') as outfile:
        cases = int(next(infile))

        for case in range(1, cases+1):
            ac, aj = map(int, next(infile).split())

            # Terrible, I know.
            c_remaining = 720
            j_remaining = 720
            times = [None]*1440

            for _ in range(ac):
                c, d = map(int, next(infile).split())
                for i in range(c, d):
                    times[i] = 0
                c_remaining -= d-c

            for _ in range(aj):
                j, k = map(int, next(infile).split())
                for i in range(j, k):
                    times[i] = 1
                j_remaining -= k-j

            # Absolutely terrible.
            while c_remaining > 0:
                zero_gaps = set()
                last_item_index = None
                last_item = None

                for i in range(1440*2):
                    if times[i%1440] == 0:
                        if last_item == 0 and (i-last_item_index)%1440 > 1:
                            zero_gaps.add((last_item_index+1, i))
                        last_item = 0
                        last_item_index = i
                    elif times[i%1440] == 1:
                        last_item = 1
                        last_item_index = i

                if not zero_gaps:
                    break

                e, f = min(zero_gaps, key=lambda a:(a[1]-a[0])%1440)
                if f-e > c_remaining:
                    break

                c_remaining -= f-e
                for i in range(e, f):
                    times[i%1440] = 0

            # Still terrible
            while j_remaining > 0:
                one_gaps = set()
                last_item_index = None
                last_item = None
                
                for i in range(1440*2):
                    if times[i%1440] == 0:
                        last_item = 0
                        last_item_index = i
                    elif times[i%1440] == 1:
                        if last_item == 1 and (i-last_item_index)%1440 > 1:
                            one_gaps.add((last_item_index+1, i))
                        last_item = 1
                        last_item_index = i

                if not one_gaps:
                    break

                e, f = min(one_gaps, key=lambda a:(a[1]-a[0])%1440)
                if f-e > j_remaining:
                    break

                j_remaining -= f-e
                for i in range(e, f):
                    times[i%1440] = 1

            if all(x == None for x in times):
                score = 2
            else:
                score = 0
                pairs = []

                for i in range(1440):
                    if times[i] != times[(i+1)%1440]:
                        pairs.append((times[i], times[(i+1)%1440]))

                if pairs[0][0] == None:
                    pairs = pairs[1:] + pairs[:1]

                i = 0
                while i < len(pairs):
                    if pairs[i][1] == None:
                        if pairs[i][0] == pairs[i+1][1]:
                            score += 2
                        else:
                            score += 1
                        i += 2
                    else:
                        score += 1
                        i += 1

            print(case, score)
            print("Case #{}: {}".format(case, score), file=outfile)
