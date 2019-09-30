import sys
import re

# Hopcroft-Karp bipartite max-cardinality matching and max independent set
# David Eppstein, UC Irvine, 27 Apr 2002
import bipartite_matching

input_file = open(sys.argv[1], 'r')
nb_tests = int(input_file.readline())

for i in range(nb_tests):
    nb_titles = int(input_file.readline())
    titles = {}
    first_titles = set({})
    second_titles = set({})
    for j in range(nb_titles):
        title = input_file.readline()[:-1].split(' ')
        first_titles = first_titles | {title[0]}
        second_titles = second_titles | {title[1]}
        #print(title)
        if title[0] in titles:
            titles[title[0]].append(title[1])
        else:
            titles[title[0]] = [ title[1] ]

    matching = bipartite_matching.bipartiteMatch(titles)[0]
    #print(matching)
    len_m = len(matching)
    len_f = len(first_titles)
    len_s = len(second_titles)
    #print('nb first:', len_f, ', nb_second:', len_s)
    #print('titles to cover:', len_m + (len_f + len_s - len_m * 2))
    cover = len_f + len_s - len_m
    print('Case #', i + 1, ': ', nb_titles - cover, sep='')
    #graph = {  0:[0], 1:[0,2], 2:[1,2,3], 3:[2], 4:[2]  }
    #print(bipartiteMatch(graph)[0])
