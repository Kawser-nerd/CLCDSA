import string

encrypted = ['ejp mysljylc kd kxveddknmc re jsicpdrysi', 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'de kr kd eoya kw aej tysr re ujdr lkgc jv', 'y qeez']
decrypted = ['our language is impossible to understand', 'there are twenty six factorial possibilities', 'so it is okay if you want to just give up', 'a zooq']

mapping = {}

for enc, dec in zip(encrypted, decrypted):
    for i in xrange(len(enc)):
        mapping[enc[i]] = dec[i]

def decrypt_string(s):
    dec = ''
    for c in s:
        dec += mapping[c]
    return dec

N = int(raw_input())
for i in xrange(N):
    line = raw_input().split()
    print ('Case #%d: ' % (i + 1)) + ' '.join(decrypt_string(s) for s in line)


