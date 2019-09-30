#!/usr/bin/python

import sys

zipcodes=[]
flights={}

def solve(path,avail):
  #Try to solve the problem given that we have started with the given path
  #and avail indicates whether we can fly outbound from each city in that path
  if len(path)==len(zipcodes):
    return path
  #Compute list of unvisited cities we can reach and sort by zip code
  reachable=[]
  for j in xrange(len(path)):
    if avail[j]:
      for flight in flights[path[j]]:
        if flight not in path and flight not in reachable:
          reachable.append((zipcodes[flight-1],flight))
  reachable.sort()
  #For each reachable city, figure out how far back in our path we have to
  #return to get to it, and go there, until we find a solution
  for zip,city in reachable:
    navail=avail[:]
    for j in xrange(len(path)-1,-1,-1):
      if navail[j]:
        if city in flights[path[j]]:
          break
        else:
          navail[j]=False
    navail.append(True)
    x=solve(path+[city],navail)
    if x is not None:
      return x
  #failure
  return None
  

t=int(sys.stdin.readline())
for caseno in xrange(t):
  lin=sys.stdin.readline().split()
  n=int(lin[0])
  m=int(lin[1])
  zipcodes=[]
  reachable=[]
  for j in xrange(n):
    zip=sys.stdin.readline().strip()
    zipcodes.append(zip)
    reachable.append((zip,j+1))
  reachable.sort()
  flights={}
  for j in xrange(n):
    flights[j+1]=[]
  for j in xrange(m):
    lin=sys.stdin.readline().split()
    i=int(lin[0])
    j=int(lin[1])
    flights[i].append(j)
    flights[j].append(i)
  #try each starting city
  for zip,city in reachable:
    x=solve([city],[True])
    if x is not None:
      #solved
      res=""
      for city in x:
        res+=zipcodes[city-1]
      sys.stdout.write("Case #"+repr(caseno+1)+": "+res+"\n")
      break
