


dull_modifiers = [(0,0,0),(0,0,1),(0,1,1)]
surp_modifiers = [(-1,0,1),(-1,1,1),(0,0,2)]

def solvecase(target, surprising, values):
    total_dull_count = 0
    surp_deltas = []
    for v in values:
        dull_scores = [(v//3) + m for m in dull_modifiers[v%3]]
        surp_scores = [(v//3) + m for m in surp_modifiers[v%3]]
        dull_count = int(bool(len([s for s in dull_scores if s>=target])))
        surp_count = int(bool(len([s for s in surp_scores if s>=target])))
        total_dull_count += dull_count
        if any((score<0) or (score>10) for score in surp_scores):
            # This *cannot* be a surprising score
            continue
        surp_deltas.append(surp_count - dull_count)
        #print "dull: {0}, surprising: {1}, dull_count: {2}, delta: {3}".format(dull_scores, surp_scores, dull_count, surp_count-dull_count)
    surp_deltas.sort()

    count = total_dull_count + (sum(surp_deltas[-surprising:]) if surprising>0 else 0)
    return count

def main():
    cases = int(raw_input())
    for c in range(cases):
        values = map(int, raw_input().split())
        #number = values[0]
        surprising = values[1]
        target = values[2]
        totals = values[3:]
        count = solvecase(target, surprising, totals)
        print "Case #{0}: {1}".format(c+1, count)

main()
