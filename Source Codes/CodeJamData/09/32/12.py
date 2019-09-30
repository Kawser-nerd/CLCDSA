class Warm(object):
    def __init__(self, x, y, z,
                 vx, vy, vz):
        self.x = x
        self.y = y
        self.z = z
        self.vx = vx
        self.vy = vy
        self.vz = vz
    

def minM(warms):
    N = len(warms)*1.0
    sigmax = 0
    sigmay = 0
    sigmaz = 0
    
    sigmavx = 0
    sigmavy = 0
    sigmavz = 0
    
    for warm in warms:
        sigmax += warm.x
        sigmay += warm.y
        sigmaz += warm.z
        sigmavx += warm.vx
        sigmavy += warm.vy
        sigmavz += warm.vz
        
    sigmax /= N
    sigmay /= N
    sigmaz /= N
    sigmavx /= N
    sigmavy /= N
    sigmavz /= N
    
    a = sigmavx**2 + sigmavy**2 + sigmavz**2
    b = 2*(sigmax*sigmavx + sigmay*sigmavy + sigmaz*sigmavz)
    
    if a == 0:
        t = 0
    else:
        t = -0.5 * b / a
    
    if t < 0:
        t = 0
        
    m = (sigmax+sigmavx*t)**2 + (sigmay+t*sigmavy)**2 + (sigmaz+t*sigmavz)**2
    m = m**0.5
    
    return m, t
    

def init_warm(ws):
    warms = list()
    for line in ws:
        tmp = line.strip().split()
        x = int(tmp[0])
        y = int(tmp[1])
        z = int(tmp[2])
        vx = int(tmp[3])
        vy = int(tmp[4])
        vz = int(tmp[5])
        
        w = Warm(x, y, z, vx, vy, vz)
        warms.append(w)
        
    return(warms)
    
def main(filename, out = 'result.txt'):
    rfile = open(filename)
    wfile = open(out, 'w')
    
    rfile.readline()
    f = rfile.readlines()
    case = 0
    while f:
        case += 1
        N = int(f[0].strip())
        f = f[1:]
        ws = f[0:N]
        f = f[N:]
        warms = init_warm(ws)
        m, t = minM(warms)
        wfile.write('Case #'+str(case)+': '+str(m)+' '+str(t)+'\n')
    
if __name__ == '__main__':
    import sys
    import psyco
    psyco.full()
    in_file = sys.argv[1]
    
    main(in_file) 
    
    
    
    
    
    
    
    
    
    
    
    
    
    