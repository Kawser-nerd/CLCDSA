file = 'B-large'


fin = open(file + '.in', 'r')
fout = open(file + '.out', 'w')

def search_position(letter, word):
    if letter == '-': return (len(word),)
    positions = []
    for i, l in enumerate(word):
        if l == letter:
            positions.append(i)
    return tuple(positions)
        

def algorithm():
    pass

def process():
    n, m = ( int(x) for x in fin.readline().rstrip().split(' ') )
    dictionary = []
    guess_list = []
    for i in range(0,n):
        dictionary.append(fin.readline().rstrip())
    
    for i in range(0,m):
        guess_list.append(fin.readline().rstrip())
        
    index = {}
    for letter in '-abcdefghijklmnopqrstuvwxyz':
        alpha_dic = {}
        for word in dictionary:
            position = search_position(letter, word)
            if position in alpha_dic:
                alpha_dic[position].add(word)
            else:
                alpha_dic[position] = set([word])
        index[letter] = alpha_dic
    #print index        
        
    result = []
    for i in range(0,m):
        guess = '-'+ guess_list[i]
        print guess
        score = {}
        for word in dictionary:
            score[word] = 0
        
        wordset_list = [set(dictionary)]
        for disc in guess:
            alpha_dic = index[disc]
            newwordset_list = []
            for wordset in wordset_list:
                for position, group in alpha_dic.items():
                    inter = wordset.intersection(group)
                    if len(inter) == 0: pass
                    elif len(inter) == len(wordset):
                        newwordset_list.append(wordset)
                    else:
                        if position == tuple():
                            for word in inter:
                                score[word] += 1
                        if len(inter) > 1:
                            
                            newwordset_list.append(inter)
            wordset_list = newwordset_list
        #print score
        max = -1
        candidate = ''
        for word in dictionary:
            if score[word] > max:
                max = score[word]
                candidate = word
        result.append(candidate)
    return ' '.join(result)
            
                    

num_cases = int(fin.readline().rstrip())

for i in range(1, num_cases + 1):
    result = process()
    fout.write('Case #%d: %s\n' % (i, result))

fin.close()
fout.close()