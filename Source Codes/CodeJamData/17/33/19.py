with open('C-small-1-attempt0.in') as infile:
    with open('C-small-1-attempt0.out', 'w') as outfile:
        cases = int(next(infile))

        for case in range(1, cases+1):
            n, k = map(int, next(infile).split())
            u = round(float(next(infile))*10000)
            # Make them all ints.
            p = list(map(lambda x:round(float(x)*10000), next(infile).split()))
            p.sort()

        
            p.append(10000)
            i = 0

            while u > 0 and i < len(p):
                while i < len(p) and p[i] == p[i+1]:
                    i += 1

                x = min((p[i+1] - p[i])*(i+1), u)
                for j in range(i+1):
                    p[j] += x/(i+1)
                u -= x

            product = 1
            for x in p:
                product *= x/10000

            # print([x/10000 for x in p])
            print(case, product)
            print("Case #{}: {}".format(case, product), file=outfile)
