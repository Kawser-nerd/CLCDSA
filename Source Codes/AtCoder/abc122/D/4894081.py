import itertools, math

N = int(input())

ACGTList = ["A", "G", "C", "T"]
AGCList = ["ATGC", "AGTC", "AGGC"]
for ACGT in ACGTList:
    for AGC in ["AGC", "ACG", "GAC"]:
        AGCList.append(ACGT + AGC)
        AGCList.append(AGC + ACGT)

patternObj = itertools.product(ACGTList, repeat=3)
patternDict = {}
for i, pattern in enumerate(patternObj):
    strPattern = "".join(pattern)
    patternDict[strPattern] = 0 if strPattern in ["AGC", "ACG", "GAC"] else 1

for i in range(N - 3):
    nextPatternDict = dict.fromkeys(patternDict, 0)
    for pattern in patternDict:
        for ACGT in ACGTList:
            newPattern = pattern + ACGT
            if newPattern in AGCList:
                continue
            nextPatternDict[newPattern[1:]] += patternDict[newPattern[:3]]
    patternDict = nextPatternDict.copy()

ans = 0
devide = int(math.pow(10, 9)) + 7
for pattern in patternDict:
    ans += patternDict[pattern]
    ans %= devide

print(ans)