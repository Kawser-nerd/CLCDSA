import sys

f1 = open('c:\Temp\words.txt')
words = []
for ii in range(12): words.append([])
max_len = 10
min_len = 1
for line in f1.readlines():
    line = line.strip()
    words[len(line)].append(line)

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    S = f.readline().strip()
    best_score_dict = {}
    best_score_dict[(0,0)] = 0

    for start_index in range(0, len(S)):
        tmp_keys = best_score_dict.keys()
        keys = filter(lambda x: x[1] == start_index, tmp_keys)

        for word_len in range(min_len, min(max_len+1, len(S) - start_index + 1)):
            for word in words[word_len]: # get each word of this length in turn. 
                # Look to see if the word matches what we need. 
                clashes = []
                Fail = False
                for index in range(word_len):
                    word[index]
                    if word[index] != S[start_index + index]:
                        if clashes != [] and index - clashes[-1] < 5:
                            Fail = True
                            break
                        else:
                            clashes.append(index)
                # Take no clashes into account
                first_clash = start_index + 5
                last_clash = start_index + word_len - 5
                if not Fail:
                    if clashes != []:
                        first_clash = clashes[0] + start_index
                        last_clash = clashes[-1] + start_index
                        
                    this_word_keys = filter(lambda x: x[0] <= first_clash, keys)
                    for key in this_word_keys:
                        next_poss_change_index = max(key[0], last_clash + 5)
                        if (next_poss_change_index, start_index + word_len) in best_score_dict:
                            best_score_dict[(next_poss_change_index, start_index + word_len)] = min(best_score_dict[(next_poss_change_index, start_index + word_len)], best_score_dict[key] + len(clashes))
                        else:
                            best_score_dict[(next_poss_change_index, start_index + word_len)] = best_score_dict[key] + len(clashes)
    
    least_score = 10**6
    len_S = len(S)
    for key, item in best_score_dict.items():
        if key[1] == len_S and item < least_score:
            least_score = item

    print "Case #%d:" % (t + 1), least_score
