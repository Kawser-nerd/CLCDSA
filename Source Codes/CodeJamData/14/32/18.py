def get_key(ss):
  num = 0
  for c in ss:
    num |= 1 << (ord(c) - ord('a'))
  return num

def check_pass(ss):
  used = set()
  for i in xrange(len(ss)):
    if i > 0 and ss[i] != ss[i-1] and ss[i] in used:
      return False
    used.add(ss[i])
  return True

def single_char(ss):
  return all([c == ss[0] for c in ss])

def solve(sl):
  MODFAC = 1000000007
  ans = 1

  factorial = [1]
  num = 1
  for i in xrange(1, 101):
    num *= i
    num %= MODFAC
    factorial.append(num)

  mul = []
  sin = [0]*26
  for s in sl:
    if not check_pass(s):
      #print 'nonpass A'
      return 0
    if single_char(s):
      sin[ord(s[0]) - ord('a')] += 1
    else:
      mul.append(s)

  for i in xrange(26):
    c = chr(ord('a') + i)
    ans *= factorial[sin[i]]
    ans %= MODFAC
    
    use_front = 0
    use_back = 0
    last_front = None
    last_back = None

    for j in xrange(len(mul)):
      if mul[j][0] == c:
        use_front += 1
        last_front = j
      if mul[j][-1] == c:
        use_back += 1
        last_back = j

    if use_front >= 2 or use_back >= 2:
      #print 'frontback'
      return 0
    elif use_front == 1 and use_back == 1:
      newmul = [mul[last_back] + mul[last_front]]
      for k in xrange(len(mul)):
        if k != last_front and k != last_back:
          newmul.append(mul[k])
      mul = newmul
    elif use_front == 0 and use_back == 0 and sin[i] > 0:
      mul.append(c)
    #print c, mul

  for i in xrange(len(mul)):
    if not check_pass(mul[i]):
      #print 'nonpass B'
      return 0
    for j in xrange(i+1, len(mul)):
      if get_key(mul[i]) & get_key(mul[j]) != 0:
        #print 'overlap B'
        return 0

  ans *= factorial[len(mul)]
  ans %= MODFAC
  return ans

tt = int(raw_input())
for t in xrange(1, tt+1):
  n = int(raw_input())
  sll = raw_input().split()
  ans = solve(sll)

  print 'Case #'+str(t)+': '+str(ans)

