from wrap import *

def find_all(str, substr):
    out = []
    last = str.find(substr)
    while last != -1:
        out.append(last)
        last = str.find(substr, last + 1)
    return out 
        
def filter_by(select_word, words, letter):
    select_appearance = find_all(select_word, letter)
    out = []
    for word in words:
        if select_appearance == find_all(word, letter):
            out.append(word)
    # print "filtered by %s and %s -- %s" % (select_word, letter, out)
    return out
    
def get_guesses(select_word, words, glist):
    new_words = []
    for word in words:
        if len(word) == len(select_word):
            new_words.append(word)
    return get_guesses_samewordsize(select_word, new_words, glist)

def get_guesses_samewordsize(select_word, words, glist):
    if len(words) == 1:
        return 0
    letset = set()
    for word in words:
        letset.update(word)
    i = 0
    while(glist[i] not in letset):
        i += 1
    # print "gonna guess %s" % glist[i]
    words = filter_by(select_word, words, glist[i])
    mistake = glist[i] not in select_word
    # if mistake == 1:
    #     print "saying %s for %s would be a mistake..." % (glist[i], select_word)
    return mistake + get_guesses_samewordsize(select_word, words, glist[i+1:])
     

def get_killa_word(words, glist):
    max_guesses = -1
    max_word = ""
    for word in words:
        guesses = get_guesses(word, words, glist)
        # print word, "requires", guesses, "guesses"
        if guesses > max_guesses:
            max_guesses = guesses
            max_word = word
    return max_word
        
def reader(f):
    dlen, glen = make_ints(f.readline())
    words = []
    guesses = []
    for i in xrange(dlen):
        words.append(f.readline()[:-1])
    for i in xrange(glen):
        guesses.append(f.readline()[:-1])
    killa_words = [get_killa_word(words, glist) for glist in guesses]
    return " ".join(killa_words)
    
cjwrap(reader, 'B-small-attempt0.in')