import sys,time

start_time = time.time()
try:
    if len(sys.argv) > 1:
        inname = sys.argv[1]
    else:
        inname = input("Enter input filename: ")

    assert inname.endswith('.in')
    outname = inname.replace('.in', '.out')

    with open(inname) as fin:
        with open(outname, 'w') as fout:
            num_cases = int(fin.readline())
            for case_idx in range(1,1+num_cases):
                if time.time() >= start_time + 5:
                    print ("[== Case %d of %d ==]" % (case_idx, num_cases))
                N,pD,pG = [int(x) for x in fin.readline().split()]

                answer = True
                N = min(N, 100)
                if pG == 100 and pD != 100: answer = False
                if pG == 0 and pD != 0: answer = False
                if all( (pD * D) % 100 for D in range(1,1+N)): answer = False
                    
                print("Case #{}: {}".format(case_idx, 'Possible' if answer else 'Broken'), file=fout)

except:
    import traceback
    print("Exception caught:", file=sys.stderr)
    print('-'*60, file=sys.stderr)
    traceback.print_exc(file=sys.stderr)
    print('-'*60, file=sys.stderr)
    input("Press Enter to close")
else:
    total_time = time.time() - start_time
    print("Completed in %.1f seconds" % total_time, file=sys.stderr)
    time.sleep(3)
