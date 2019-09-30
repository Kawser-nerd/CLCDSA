import math
import cPickle

import sys
sys.setrecursionlimit(10000)

slownik = None
m=10
try:
  f = open('dict.pkl')
  slownik = cPickle.load(f)
  f.close()
except IOError:
  f = open('garbled_email_dictionary.txt')
  slownik = set()
  m = 0
  for line in f:
    line=line.strip()
    slownik.add(line)
    m=max(m, len(line))
    for i in xrange(len(line)):
      word=list(line)
      word[i]='?'
      slownik.add(''.join(word))
      
    for i in xrange(len(line)-5):
      word=list(line)
      word[i]='?'
      word[i+5]='?'
      slownik.add(''.join(word))

  f.close()
  #print m
  
  f = open('dict.pkl', 'w')
  slownik = cPickle.dump(slownik, f)
  f.close()
  
  
cache = {}
  
def rec(s, ost=-5):
  global slownik, m, cache
  
  ost = max(ost, -5)
  
  if not s:
    return 0
  
  if (s, ost) in cache:
    return cache[(s, ost)]
  
  #print s, ost
  
  changes = []
  
  for i in xrange(1, min(m, len(s))+1):
    word = s[0:i]
    if word in slownik:
      #print 'w', word, ost-len(word), ost
      changes.append(rec(s[i:], ost-len(word)))
      
    
    for j in xrange(max(ost+5, 0), len(word)):
    #for j in xrange(0, len(word)):
      word2=list(word)
      word2[j]='?'
      word2=''.join(word2)
      if word2 in slownik:
        #print 'w1', word2, j-len(word)
        changes.append(rec(s[i:], j-len(word))+1)
        
    for j in xrange(max(ost+5, 0), len(word)-5):
    #for j in xrange(0, len(word)-5):
      word2=list(word)
      word2[j]='?'
      word2[j+5]='?'
      word2=''.join(word2)
      if word2 in slownik:
        #print 'w2', word2, j+5-len(word)
        changes.append(rec(s[i:], j+5-len(word))+2)
      
  #print s, changes
  if changes:
    changes = min(changes)
  else:
    #print 'dupa'
    changes = 5000
    
  cache[(s, ost)]=changes
    
  return changes
  

numcases = int(raw_input())
for i in range(1, numcases+1):
  s = raw_input()
  #print s
  cache = {}
  ch = rec(s)
  
  print 'Case #'+str(i)+': '+str(ch)