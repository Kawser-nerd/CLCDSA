def kaidan(n):
  return (n * (n - 1)) // 2


def move(l, r):
  _l = abs(l)
  _r = abs(r)

  if r < 0:
    hoge = kaidan(_l + 1) - kaidan(_r) 
  elif 0 < l:
    hoge = kaidan(_r + 1) - kaidan(_l)
  else:
    hoge = kaidan(_r + 1) + kaidan(_l + 1)
  return hoge


def lr_move(num, half, wall, is_over):
  if is_over:
    l = half
  else:
    l = wall

  r = l + num

  if l > r:
    return move(r, l)
  else:
    return move(l, r)
  

if __name__ == "__main__":
  MAX_NUM = 500
  R, G, B = map(int, input().split())
  ans = [0 for _ in range(MAX_NUM * 2 )]

  B_half = ((B - 1) // 2)
  R_half = ((R - 1) // 2)
  _B = B - 1
  _R = R - 1
  for g in range(-MAX_NUM, MAX_NUM):
    gl = g
    gr = g + G - 1

    ans[g] = sum((
      move(gl, gr),
      lr_move(_B, -B_half, gr - 99, -B_half >= gr - 99),
      lr_move(-_R, R_half, gl + 99, R_half <= gl + 99)
    ))
  print(min(ans))