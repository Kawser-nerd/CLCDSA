import sys

sys.stdin = open("C.in","r")
sys.stdout = open("C.out","w")
T = int(raw_input())
ans = ["027","143","751","935","607","903","991","335","047","943","471","055","447","463","991","095","607","263","151","855","527","743","351","135","407","903","791","135","647"]
for i in xrange(T):
      n = int(raw_input())
      print "Case #%s: %s" % (str(i+1),ans[n-2])
sys.stdin.close()
sys.stdout.close()
            
