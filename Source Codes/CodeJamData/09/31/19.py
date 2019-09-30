class Gcjt(object):
      class Testcase(object):
            def __init__(self,num,gcjt):
                  self.num = num
                  self.gcjt = gcjt
            def answer(self,answer):
                  self.gcjt.outs.write('Case #{num}: {ans}' \
                        .format(num = self.num,ans = answer) + '\n')
            def ws(self,string):
                  self.gcjt.outs.write(string)
            def rl(self):
                  return self.gcjt.ins.readline()
            def ri(self):
                  return (int(s) for s in self.rl().split())
      def __init__(self):
            filename = input('file name : ')
            self.fin = filename+ '.in'
            self.fout = filename + '.out'
      def __enter__(self):
            self.ins = open(self.fin)
            self.outs = open(self.fout,'w')
      def __exit__(self,errtype=None,errvalu=None,errtrace=None):
            self.ins.close()
            self.outs.close()
      def tests(self,num = None):
            with self:
                  if num is None: num = int(self.ins.readline())
                  for t in range(num):
                        yield self.Testcase(t+1,self)
def array(*dim):
      if len(dim)==1:    return [None]*(dim[0])
      else:return [array(*dim[1:]) for i in range(dim[0])]
def tests():
      return Gcjt().tests()
            
