a=int(input())
b=int(input())

print(min(abs(b-a),abs(a-b),
      abs(10+b-a),
      abs(10+a-b)
     ))