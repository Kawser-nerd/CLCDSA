

def inside(u, v, polygon):
  if u in polygon and v in polygon: return True
  else: return False


def cut(polygon, u, v):
  ui = polygon.index(u)
  vi = polygon.index(v)

  if ui > vi:
    tmp = u
    tmpi = ui

    u = v
    ui = vi

    v = tmp
    vi = tmpi

  p1 = polygon[ui:vi+1]
  p2 = polygon[vi:] + polygon[:ui+1]

  return p1, p2


def print_color_list(color_list, colors):
  print colors

  for color in color_list:
    print color+1,
  print ''

T = input()
for t in range(T):
  print 'Case #{0}:'.format(t+1),

  N, M = map(int, raw_input().split())
  Us = map(int, raw_input().split())
  Vs = map(int, raw_input().split())

  polygon = range(1, N + 1)
  polygons = [polygon]

  for i in range(M):
    u = Us[i]
    v = Vs[i]

    for polygon in polygons:
      if inside(u, v, polygon):
        p1, p2 = cut(polygon, u, v)

        polygons.remove(polygon)
        polygons.append(p1)
        polygons.append(p2)
        break


  max_point = max(map(len, polygons))

  finish = False
  for colors in range(max_point, 0, -1):
    for bt in range(colors ** N):
      bt_copy = bt
      color_list = []
      while bt_copy > 0:
        color_list.append(bt_copy % colors)
        bt_copy = bt_copy / colors
      while len(color_list) < N:
        color_list.append(0)


      ok = True

      for polygon in polygons:
        seen_colors = set([])

        for point_id in polygon:
          seen_colors.add(color_list[point_id-1])

        if len(seen_colors) != colors:
          ok = False

      if ok:
        print_color_list(color_list, colors)
        finish = True
        break

    if finish: break



