s = 0

class Metadat:
    def __init__(self,x,y):
        self.corner = [0]*6
        self.edge = [0]*6
        self.add_position(x,y)
        
    def checkCorner(self,x,y):
        global s
        ll = [(1,1),(1,s),(s,1),(2*s-1,s),(s,2*s-1),(2*s-1,2*s-1)]
        for i in range(6):
            if ll[i][0] == x and ll[i][1] == y:
                #print (x,y,i,s,"CORNER")
                return i
        #print (x,y,"NONE",s,"CORNER")
        return None
            
    def combineWith(self,meta):
        for i in range(6):
            self.corner[i] |= meta.corner[i]
            self.edge[i] |= meta.edge[i]
            
    def checkEdge(self,x,y):
        if x == 1:
            return 0
        elif y == 1:
            return 1
        elif x == 2*s-1:
            return 2
        elif y == 2*s-1:
            return 3
        elif x-y == s-1:
            return 4
        elif y-x == s-1:
            return 5
        else:
            return None
        
    def add_position(self,x,y):
        w = self.checkCorner(x,y)
        if w != None:
            self.corner[w] = 1
        else:
            w = self.checkEdge(x,y)
            if w != None:
                self.edge[w] = 1
        
    def has_bridge(self):
        return sum(self.corner) >= 2
        
    def has_fork(self):
        return sum(self.edge) >= 3

def alphabet(gs, m, v):
    global s
    s = gs
    i = 0
    par = []
    rnk = []
    mp = {}
    met = {}
    
    def makepar(p, q):
        par[p] = q
        met[q].combineWith(met[p])
    def set_find(p):
        q = p
        while par[p]!=p:
            p = par[p]
        while par[q]!=q:
            r = par[q]
            par[q] = p
            q = r
        return p
    def set_union(p, q):
        p = set_find(p)
        q = set_find(q)
        if rnk[p] < rnk[q]:
            makepar(p,q)
        elif rnk[p] > rnk[q]:
            makepar(q,p)
        elif p != q:
            makepar(p,q)
            rnk[q] += 1
    def union(p, q):
        try:
            set_union(mp[p],mp[q])
        except KeyError:
            pass
    def get_mp(p):
        try:
            return set_find(mp[p])
        except KeyError:
            return None
    for (x, y) in v:
        par.append(i)
        rnk.append(0)
        mp[(x,y)] = i
        met[i] = Metadat(x,y)
        
        mxr = False
        rr = [get_mp(u) for u in [(x+1,y),(x+1,y+1),(x,y+1),(x-1,y),(x-1,y-1),(x,y-1)]]
        rrcopy = rr[:]
        ss = []
        def prev(p):
            return 5 if p == 0 else p-1
        for j in range(6):
            ss.append(rr[j]==rr[prev(j)])
        for j in range(6):
            if ss[j]:
                rr[j] = None
        for j in range(6):
            if rr[j] == None:
                continue
            for k in range(2,4):
                if rr[j] == rr[(j+k)%6]:# and rr[prev((j+k)%6)] != rr[j]:
                    mxr = True
                    break
        
        union((x,y),(x+1,y))
        union((x,y),(x-1,y))
        union((x,y),(x,y+1))
        union((x,y),(x,y-1))
        union((x,y),(x+1,y+1))
        union((x,y),(x-1,y-1))
        mx = met[set_find(i)]
        mxb = mx.has_bridge()
        mxf = mx.has_fork()
        
        i += 1
        ans = ""
        if mxb:
            ans += "-bridge"
        if mxf:
            ans += "-fork"
        if mxr:
            ans += "-ring"
            #print rr
            #print rrcopy
        if mxb or mxf or mxr:
            return (ans+" in move %d"%i)[1:]
    return "none"

if __name__ == "__main__":
    fn = open("B-large.in","r")
    tcase = int(fn.readline())
    for xx in range(tcase):
        kk = fn.readline()
        zl = [int(k) for k in kk.split()]
        ss = zl[0]
        mm = zl[1]
        vv = []
        for y in range(mm):
            kk = fn.readline()
            zp = [int(k) for k in kk.split()]
            vv.append((zp[0],zp[1]))
        print "Case #%d: %s" % (xx+1, alphabet(ss,mm,vv))
