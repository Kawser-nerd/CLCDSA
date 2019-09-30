for tc in range(int(input())):
  n = list(map(int, list(input())))
  
  found = False
  
  def f(x, y, z):
    if (x == len(n)): 
      global found
      found = True
      return '0'
      
    ret = ''
    for i in range(9 if y else n[x], z-1, -1):
      ret = str(i) + f(x+1, y or (i < n[x]), i)
      if (found): break
      
    return ret
    
  print("Case #" + str(tc+1) + ": " + str(int(f(0, False, 0)) // 10))