from itertools import chain
ciphertexts = [
    "y qee",
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"]
plaintexts = [
    "a zoo",
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"]
alphaset = set(map(chr, range(ord('a'), ord('z')+1)))
z = zip("".join(ciphertexts), "".join(plaintexts))
decoder = dict(z)
missingkeys = alphaset.difference(decoder.keys())
missingvalues = alphaset.difference(decoder.values())
assert len(missingkeys)<=1
assert len(missingvalues)<=1
decoder[missingkeys.pop()] = missingvalues.pop()

cases = int(raw_input())
for c in range(cases):
    ct = raw_input().strip()
    pt = "".join(decoder[ch] for ch in ct)
    print "Case #{0}: {1}".format(c+1, pt)
