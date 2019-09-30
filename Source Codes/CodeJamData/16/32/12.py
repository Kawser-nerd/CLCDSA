def binary(n):
  if n == 0:
    return ""
  return ("1" + binary(n/2) if n%2 == 1 else "0" + binary(n/2))
  

T = int(raw_input())
for test_case in range(T):
  [B, M] = [int(x) for x in raw_input().split()]
  maxval = 2**(B-2)
  if M > maxval:
    answer = "IMPOSSIBLE"
  elif M == maxval:
    answer = "POSSIBLE\n"
    for i in range(B):
      line = [("1" if j > i else "0") for j in range(B)]
      answer += ''.join(line) + ("" if i == B-1 else "\n")
  else:
    answer = "POSSIBLE\n"
    b = binary(M) + "0"*100
    for i in range(B-1):
      line = [("1" if j > i else "0") for j in range(B-1)]
      last_letter = "0" if i == 0 else b[i-1]
      line.append(last_letter)
      answer += ''.join(line) + ("" if i == B-1 else "\n")
    answer += "0"*B
    
  print "Case #%s: %s"%(test_case+1, answer)
