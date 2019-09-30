import sys

def shift(a, sh):
    return [s[sh:] + s[:sh] for s in a]

def eqNoSym(a1, a2):
    m = len(a1[0])
    return any(a1 == shift(a2, sh) for sh in range(m))

def eqNoFlip(a1, a2):
    #return eqNoSym(a1, a2)
    return eqNoSym(a1, a2) or eqNoSym(a1, [a2i[::-1] for a2i in a2])

def eq(a1, a2):
    return eqNoSym(a1, a2)
    #return eqNoFlip(a1, a2) or eqNoFlip(a1, a2[::-1])
    

inp = sys.stdin.read().split('========')
answers = [[s.strip() for s in ans.strip().split()] for ans in inp[1:]]
#print(answers)

uniq = []
for a in answers:
    if all(not eq(a, u) for u in uniq):
        uniq.append(a)

print(len(uniq), ',')
#print(uniq)
