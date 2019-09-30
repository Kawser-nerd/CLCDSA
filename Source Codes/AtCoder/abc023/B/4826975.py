N = int(input())
S = input()
count = 0
kouho = "b"
while True:
      if kouho == S:
            print(count)
            break
      kouho = "a"+kouho+"c"
      count+=1
      if kouho == S:
            print(count)
            break
      kouho = "c"+kouho+"a"
      count+=1
      if kouho == S:
            print(count)
            break
      kouho = "b"+kouho+"b"
      count+=1
      if kouho == S:
            print(count)
            break
      if count>N:
            print(-1)
            break