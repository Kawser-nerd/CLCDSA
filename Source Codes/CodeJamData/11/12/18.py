# Usage:
# python script.py input_file output_file
# If output_file is not specified, it simply
# writes the result to console
# Lines between #---v and #---^ are part of
# the template and should not be edited.

#----------v
import sys
#----------^

#----------v
output = None
if len(sys.argv) == 3:
    output = open(sys.argv[2], 'w')
input = open(sys.argv[1])
#----------^

#----------v
for n in range(int(input.readline())):
#----------^
    n_words, n_lists = map(int, input.readline().split())
    words = []
    for i in range(n_words):
        words.append(input.readline().split()[0])
    result = []
    
    for i in range(n_lists):
        llist = input.readline().split()[0]
        best_score = -1
        best_word = ""
        for w in words:
            template = ["_"] * len(w)
            score = 0
            for ch in llist:
                if '_' not in template:
                    break
                matches = False
                for w2 in words:
                    if len(w2) != len(template):
                        continue
                    flag = True
                    try:
                        w2.index(ch)
                    except:
                        flag = False
                    if not flag:
                        continue
                    for i2 in range(len(w2)):
                        if (template[i2] not in ('_', w2[i2])) or \
                          (template[i2] == '_' and w2[i2] in llist[:llist.index(ch)]):
                            flag = False
                            break
                    if not flag:
                        continue
                    matches = True
                    break
                if matches:
                    try:
                        w.index(ch)
                        for i2 in range(len(w)):
                            if w[i2] == ch:
                                template[i2] = ch
                    except:
                        score += 1
            if score > best_score:
                best_score = score
                best_word = w
        result.append(best_word)
    result = " ".join(result)
#----------v
    print("Case #"+str(n+1)+": "+str(result))
    if len(sys.argv) == 3:
        output.write("Case #"+str(n+1)+": "+str(result)+"\n")
if len(sys.argv) == 3:
    output.close()
#----------^










