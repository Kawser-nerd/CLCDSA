def main():
  f = open('B.in', 'r')
  T = int (f.readline())

  for t in range(1, T+1):
    print 'Case #' + str(t) + ':',
    CPC = 2.0
    C, F, X = map(float, f.readline().split())
    timeFarms = 0
    timeTotal = X / CPC
    while (1):
      timeFarms += C / CPC
      CPC += F
      timeNew = timeFarms + X / CPC
      if (timeNew > timeTotal):
        break
      timeTotal = timeNew
    print timeTotal
    #print C, F, X
  
if __name__ == "__main__":
    main()
