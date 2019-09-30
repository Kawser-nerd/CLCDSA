from collections import defaultdict
from collections import Counter
from multiprocessing import Pool

def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret


def intize(sentences):
    words = {}
    i = 0
    for sentence in sentences:
        for word in sentence.split():
            if word not in words:
                words[word] = i
                i += 1
    def transform(sentence):
        return [words[w] for w in sentence.split()]

    sentences = map(transform, sentences)
    return sentences

def f(sentences):
        sentences = intize(sentences)
        eng, fre, sentences = sentences[0], sentences[1], sentences[2:]

        n = len(sentences)
        best_ans = 99999999
        for bt in xrange(1<<n):
            ew = set()
            fw = set()
            for word in eng:
                ew.add(word)
            for word in fre:
                fw.add(word)
            for i, sentence in enumerate(sentences):
                for word in sentence:
                    if (1<<i) & bt:
                        ew.add(word)
                    else:
                        fw.add(word)

            ans = len(ew&fw)
            best_ans = min(best_ans, ans)
        return best_ans





def main():
    p = Pool(8)
    inp = []
    for T in range(1, 1+input()):
        N = input()
        sentences = [raw_input() for _ in range(N)]
        inp.append(sentences)
    anss = p.map(f, inp)

    for i, ans in enumerate(anss):
        print "Case #%d: %d" % (i, ans)




main()
