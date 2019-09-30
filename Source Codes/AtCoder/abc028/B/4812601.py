from collections import Counter
S = [i for i in input()]
ans = []
ans.append(str(S.count("A")))
ans.append(str(S.count("B")))
ans.append(str(S.count("C")))
ans.append(str(S.count("D")))
ans.append(str(S.count("E")))
ans.append(str(S.count("F")))
print(" ".join(ans))