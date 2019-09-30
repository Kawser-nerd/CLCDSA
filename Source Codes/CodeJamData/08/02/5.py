
import sys

def convertTime(x):
    return int(x[0:2])*60 + int(x[3:])

class Trip:
    def __init__(self, f, name):
        self.depart, self.arrive = \
            (convertTime(x) for x in f.readline().split())
        self.name = name
        #print self
    def departTime(self):
        return self.depart
    def arriveTime(self):
        return self.arrive
    def departStation(self):
        return self.name
    def arriveStation(self):
        return 1-self.name
    def __repr__(self):
        return 'Trip<%c %02d:%02d-%02d:%02d>'% ('B' if self.name else 'A',
            self.depart/60,self.depart%60,self.arrive/60,self.arrive%60)
def main():
    f = sys.stdin
    N = int(f.readline())
    for i in range(N):
        T = int(f.readline())
        NA, NB = (int(x) for x in f.readline().split())
        trips = []
        # station A=0, B=1
        for j in range(NA):
            trips.append(Trip(f, 0))
        for j in range(NB):
            trips.append(Trip(f, 1))
        starts = [0,0]
        waits = [[],[]]
        trips.sort(key=Trip.departTime)
        for trip in trips:
            s = trip.departStation()
            for train in waits[s]:
                if train.arriveTime() + T <= trip.departTime():
                    waits[s].remove(train)
                    break
            else:
                starts[s] += 1
            s = waits[trip.arriveStation()]
            s.append(trip)
            s.sort(key=Trip.arriveTime, reverse=True)
        print 'Case #%d:'%(i+1), starts[0], starts[1]

if __name__=='__main__':
    main()
