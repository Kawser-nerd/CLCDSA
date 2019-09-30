#!/usr/bin/python

class Node:
    def __init__(self):
        self.p = 0.0
        self.feature = ""
        self.yes = None
        self.no = None
    def read(self,el,idx):
        self.p = float(el[idx])
        idx = idx + 1
        if len(el)==idx:return idx
        if (el[idx][0] <='9') and (el[idx][0]>='0'):
            return idx
        self.feature = el[idx]
        self.yes = Node()
        self.no = Node()
        idx = self.yes.read(el,idx+1)
        return self.no.read(el,idx)
    def __str__(self):
        s = "p:"+str(self.p)+" "
        if self.yes != None:
            s = s + "feature: "+self.feature+"\n"
            s = s + str(self.yes) +"\n"+ str(self.no)
        return s
    def cute(self,a):
        if self.feature == "":
            return self.p
        if self.feature in a.features:
            return self.p*self.yes.cute(a)
        else:
            return self.p*self.no.cute(a)

class Animal:
    def __init__(self):
        self.name = None
        self.features = []
    def read(self):
        li = raw_input().split()
        self.name = li[0]
        self.features = li[2:]
        #print self.features
    def __str__(self):
        s = self.name + str(self.features)
        return s



t = int(raw_input())
for i in range(t):
    n = int(raw_input())
    el = []
    for j in range(n):
        s = raw_input().replace('(',' ').replace(')',' ').split()
        el.extend(s)
    root = Node()
    root.read(el,0)
    #print el
    #print root
    a = int(raw_input())
    animals = []
    for j in range(a):
        aa = Animal()
        aa.read();
        animals.append(aa)
    #print animals
    print "Case #%d:"%(i+1)
    for aa in animals:
        print "%f"%(root.cute(aa))
