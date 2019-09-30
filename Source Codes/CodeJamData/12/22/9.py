#!/usr/bin/python
'''
shelajev@gmail.com
'''
import sys
from os.path import abspath
from subprocess import call
from Queue import deque

DEBUG = 1

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def solve(H, N, M, c, f):
  start = (0, 0)
  times = [[1<<31]*M for _ in range(N)]
  ids = [[0]*M for _ in range(N)]
  times[0][0] = 0
  q = deque()
  q.append(start)
  while q:
    x, y = q.popleft()
    ids[x][y] = 1
    for k in range(4):
      if x + dx[k] < 0 or x + dx[k] >= N:
        continue
      if y + dy[k] < 0 or y + dy[k] >= M:
        continue
      nx, ny = x + dx[k], y + dy[k]
      if c[nx][ny] - f[x][y] < 50 or c[nx][ny] - f[nx][ny] < 50 or c[x][y] - f[nx][ny] < 50:
        continue  
      curtime = times[x][y]
      curlvl = max(f[x][y], H - 10 * curtime)
      
      waitingTime = max(0, (curlvl - (c[nx][ny] - 50)) / 10.0)
      
      dt = 1
      if curtime == 0 and waitingTime == 0:
        dt = 0
      elif f[x][y] + 20 > H - 10.0 * (curtime + waitingTime):
        dt = 10
      
      if curtime + dt + waitingTime < times[nx][ny]:
        times[nx][ny] = curtime + dt + waitingTime
        if ids[nx][ny] == 0:
          q.append((nx, ny));
        elif ids[nx][ny] == 1:
          q.appendleft((nx, ny))
        ids[nx][ny] = 1
        
#  for i in range(N):
#    print times[i]
  return times[N-1][M-1]
    
  

def main():
  problem = 'B'
#  filename = None
#  filename = 'input-%s.sample' % problem
#  attempt = 0
#  filename = '%s-small-attempt%s' % (problem, attempt)
  filename = '%s-large' % problem
  if not filename:
    input_file = sys.stdin
    output_path = 'sample.txt'
  else:
    input_file = open('in/%s.in' % filename, 'r')
    output_path = 'out/%s.out' % filename
  output_file = open(output_path, 'w')
  T = int(input_file.readline().rstrip())
  for t in range(1, T+1):
    line = input_file.readline().rstrip().split()
    H, N, M = int(line[0]), int(line[1]), int(line[2])
    ceilings = [None] * N
    for i in range(N):
      ceilings[i] = map(int, input_file.readline().rstrip().split())
    floors = [None] * N
    for i in range(N):
      floors[i] = map(int, input_file.readline().rstrip().split())
      
    ans = solve(H, N, M, ceilings, floors)
    msg = 'Case #%s: %s' % (t, ans)
    if filename is None or DEBUG:
      print msg
    output_file.write('%s\n' % msg)
  output_file.close()
  return output_path
    
if __name__ == '__main__':
  output = main()
  print 'Holy Batman! I\'ve just finished crunching it! :)'
  print 'It\'s time to submit!'
  print 'Output file: ', abspath(output)
  call(['cvlc',  'etc/tada.mp3', 'vlc://quit'])