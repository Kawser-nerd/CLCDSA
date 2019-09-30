S=input()
if len(S)==1:
    print(S)
else:
    bs=[bin(i)[2:].zfill(len(S)-1) for i in range(2**(len(S)-1))]
    operators=[['' if b[i]=='0' else '+' for i in range(len(S)-1)] for b in bs]
    formulas=[''.join([S[j]+operator[j] for j in range(len(S)-1)])+S[-1] for operator in operators]
    print(sum([eval(formula) for formula in formulas]))