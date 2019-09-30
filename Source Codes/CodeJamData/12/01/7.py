import sys

mapping = {}

def init_mapping():
    encoded = ["ejp mysljylc kd kxveddknmc re jsicpdrysi",
            "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
            "de kr kd eoya kw aej tysr re ujdr lkgc jv",
            "y qee z"
            ]
    decoded = ["our language is impossible to understand",
            "there are twenty six factorial possibilities",
            "so it is okay if you want to just give up",
            "a zoo q"
            ]
    for i in xrange(len(encoded)):
        for j in xrange(len(encoded[i])):
            if encoded[i][j] in mapping and mapping[encoded[i][j]] != decoded[i][j]:
                raise Exception("Multiple mapping for %s" % encoded[i][j])
            mapping[encoded[i][j]] = decoded[i][j]


def decode(sentence):
    return ''.join(map(lambda x : mapping.get(x, x), sentence))


if __name__ == "__main__":
    init_mapping()
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        result = decode(sys.stdin.readline().strip())
        print "Case #%d: %s" % (i + 1, result)
