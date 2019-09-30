hi = int(input())
if(hi < 100):
    print("{0:02d}".format(0))
elif(hi >= 100 and hi <= 5000):
    print("{0:02d}".format(int(hi / 100)))
elif(hi >= 6000 and hi <= 30000):
    print("{0:02d}".format(int(hi / 1000 + 50)))
elif(hi >= 35000 and hi <= 70000):
    print("{0:02d}".format(int((hi / 1000 - 30) / 5 + 80)))
elif(hi > 70000):
    print("{0:02d}".format(89))