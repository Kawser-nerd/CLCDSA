
def LoadInput():

   with open("input.txt") as f:
      return f.read()
   
def Output(text):

   with open("output.txt", "w") as f:
      f.write(text)

def ParseInput(text):

    text = text.split('\n')

    caseCount = int(text.pop(0))

    testCases = []

    for i in range(caseCount):

       testCases += [ map(int,text.pop(0).split()) ]
       
    return testCases

def DoTestCase(case):

    a1, a2, b1, b2 = case

    result = 0
    
    for a in xrange(a1, a2 + 1):
        for b in xrange(b1, b2 + 1):

            low, high = a, b
            
            if a > b:
                low, high = b, a

            if b >= a*2:
                result += 1
            else:
                turns = 0
                while low > 0:
                    turns += 1
                    high = high - low
                    low, high = high, low

                if turns % 2 == 0:
                    result += 1
                
            

    return result
                
   

def main():

    testCases = ParseInput(LoadInput())

    result = []
    
    for i, case in enumerate(testCases):
        result.append("Case #{0}: {1}".format(i + 1, DoTestCase(case)))

    result = '\n'.join(result)

    Output(result)
    print "done, result:"
    print result
  

if __name__ == "__main__":

    main()
