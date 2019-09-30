s=input()
alphabet=sorted(map(chr,range(97,123)))
print("None" if set(alphabet)==set(list(s)) else sorted(set(alphabet)-set(list(s)))[0])