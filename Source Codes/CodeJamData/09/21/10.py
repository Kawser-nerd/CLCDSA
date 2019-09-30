import sys

class Node:
  def __init__(self, attr, weight):  
    self.attr = attr
    self.weight = weight
    self.childs = []
    
  def appendChild(self, node):
    self.childs.append( node )
  

def splitParen(desc):
  desc = desc.strip()[1:-1]
  ret = []
  last = 0
  cnt = 0
  
  for cur in range( len(desc) ):
    if desc[cur] == "(":
      if cnt == 0:
        if last == 0:
          ret.append( desc[last:cur] )
        last = cur
      cnt += 1
    elif desc[cur] == ")":
      cnt -= 1
      if cnt == 0:
        ret.append( desc[last:cur+1] )
  
  if last == 0:
    ret.append( desc )
  return ret

def parseToTree(desc):
  ps = splitParen(desc)
  if len(ps) == 1:
    return Node( "", float(ps[0]) )
  
  root = Node( ps[0].split(" ")[1].strip(), float( ps[0].split(" ")[0].strip() ) )
  for ch in ps[1:]:
    root.appendChild( parseToTree(ch) )
  return root
  
def probability(attrs, node):
#  print node.attr, node.weight
  if node.attr == "" :    # leaf
    return node.weight
    
  if node.attr in attrs:
    return node.weight * probability(attrs, node.childs[0])
  else:
    return node.weight * probability(attrs, node.childs[1])
  
if __name__ == "__main__":

  infile = open( sys.argv[1], "r" )
  outfile = open( "A.out", "w" )
  
  N = int( infile.readline().strip() )
  
  for case in range(N):
    nlines = int( infile.readline().strip() )
    desc = ""
    for x in range(nlines):
      desc += infile.readline().strip()
    tree = parseToTree( desc )
    
    outfile.write( "Case #%d:\n" % (case+1) )
    nanis = int( infile.readline().strip() )
    for x in range(nanis):
      animal = infile.readline().strip()
      animal = [ item.strip() for item in animal.split(" ") ]
      outfile.write( "%.7f\n" % probability( animal[2:], tree ) )

  infile.close()
  outfile.close()
  


