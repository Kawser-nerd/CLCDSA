def main():
  S = map(int,list(input()))
  K = int(input())
  for i,n in enumerate(S):
    if n == 1:
      K -= n
      continue
    if K>0:
      return n
    else:
      return 1
  return 1

if __name__ == '__main__':
  print(main())