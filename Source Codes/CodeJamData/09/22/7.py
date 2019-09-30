import sys



def findNext(number):
  digits = [ ch  for ch in number.strip() ]
  sorted = list(digits)
  sorted.sort()
  
  if len(number) == 1:
    return number+"0"
    
  cur = len(digits)-2
  while cur >= 0:
    if digits[cur] < digits[cur+1]:
      break
    cur -= 1
      
  if cur == -1:   # maximum number
    ret = "".join(sorted)
    ret = ret.replace("0", "")
    ret = ret[0] + "0"* (digits.count("0")+1) + ret[1:]
    return ret
  
  else:
    ret = number[:cur]
    first = min( [ dd for dd in digits[cur:] if dd > number[cur] ] )
    ret += first
    remains = digits[cur:]
    remains.sort()
    remains.remove(first)
    
    ret += "".join(remains)
    return ret
  
def compare(A, B):
  pA = [ ch  for ch in A.strip()  if ch != "0" ]
  pB = [ ch  for ch in B.strip()  if ch != "0" ]
  
  pA.sort()
  pB.sort()
  return "".join(pA) == "".join(pB)
  
def findNext2(number):
  num = int(number)+1
  while 1:
    if compare( str(num), number) :
      return str(num)
    num += 1

if __name__ == "__main__":
  infile = open( sys.argv[1], "r" )
  outfile = open( "resultB.out", "w" )
  
  N = int( infile.readline().strip() )
  for case in range(0, N):
    input = infile.readline().strip()
    outfile.write( "Case #%d: %s\n" % (case+1, findNext(input) ) )
#    r2 =  findNext2(input)
#    print case+1, findNext(input) == r2, r2
  
  
  infile.close()
  outfile.close()
