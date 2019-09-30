import sys

def parseInput(fname):
  f = open(fname, 'r')
  text = f.readlines()
  f.close()

  testCases = []
  cases = int(text[0])
  cnt = 1
  for i in range(cases):
    string = text[cnt].split(" ")
    cnt += 1
    testCases.append([int(a) for a in string])
  return testCases


def runCase(case):
  N = case[0]
  M = case[1]
  target = case[2]
  print N,M,target
  if N*M < target:
    return "IMPOSSIBLE"
  for x1 in range(N+1):
    for y1 in range(M+1):
      for x2 in range(N+1):
        for y2 in range(M+1):
          for x3 in range(N+1):
            for y3 in range(M+1):
              if abs(-x2*y1 + x3*y1 + x1*y2 - x3*y2 - x1*y3 + x2*y3) == target:
                return " ".join([str(x1),
                                str(y1),
                                str(x3),
                                str(y3),
                                str(x2),
                                str(y2)])
  return "IMPOSSIBLE"

def area(x1,y1,x2,y2,x3,y3):
  return (-x2*y1 + x3*y1 + x1*y2 - x3*y2 - x1*y3 + x2*y3)

def main(inputs=["test"]):
  for inputf in inputs:
    cases = parseInput(inputf+".in")
    res = []
    i = 1
    for case in cases:
      res.append((i,runCase(case)))
      i += 1
      
    output = ["\n".join("Case #%s: %s" % (num, ans) for num,ans in res)]
    print output
    outf = open(inputf+".out",'w')
    outf.write("\n".join("Case #%s: %s" % (num, ans) for num,ans in res))
    outf.close()

if __name__=="__main__":
  if sys.argv[1:]:
    main(sys.argv[1:])
  else:
    main()
