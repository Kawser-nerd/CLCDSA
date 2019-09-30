def longest_prefix(string1, string2):
  answer = 0
  n = min(len(string1), len(string2))
  for i in range(1,n+1):
    if string1[-i:] == string2[:i]:
      answer = i
  return answer

def max_repetitions(a,b,c):
  if a < b:
    return 0
  answer = 1
  a -= b
  answer += a/(b-c)
  return answer

def check_letters_are_there(a,b):
  for c in a:
    if c not in b:
      return False
  return True

def list_of_prefixness(x,payment_word,typewriter):
  answer = []
  for c in typewriter:
    monkey_write = payment_word[:x] + c
    if monkey_write == payment_word:
      finishedness = 1.0
      prefixness = longest_prefix(monkey_write, payment_word[:-1])
    else:
      finishedness = 0
      prefixness = longest_prefix(monkey_write,payment_word)
    answer.append([prefixness,finishedness])
  return answer

T = int(raw_input())

for testcase in range(T):
  [k,l,s] = [int(x) for x in raw_input().split()]
  typewriter = raw_input()
  payment_word = raw_input()
  if not check_letters_are_there(payment_word, typewriter):
    max_payment = 0
    average_payment = 0
  else:
    max_self_overlap = longest_prefix(payment_word, payment_word[:-1])
    max_payment = max_repetitions(s,len(payment_word),max_self_overlap)
    list_of_list = [list_of_prefixness(x,payment_word,typewriter) for x in range(len(payment_word))]
    p = float(len(typewriter))
    dp = {}
    for z in range(s+1):
      for y in range(z+1):
        x = z-y
        if x >= len(payment_word):
          continue
        if y == 0:
          dp[(x,y)] = 0
        else:
          answer = 0
          for i in range(len(typewriter)):
            [prefixness,finishedness] = list_of_list[x][i]
            answer += finishedness/p
            answer += dp[(prefixness,y-1)]/p
          dp[(x,y)] = answer
    average_payment = dp[(0,s)]
    
  print "Case #%s: %.9f"%(testcase+1,max_payment-average_payment)

