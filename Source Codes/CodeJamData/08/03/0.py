import sys
import math

def proc_case():
    # parse
    r_fly,r_outer,thickness,r_str,gap=map(float,sys.stdin.readline().split())

    # calculate
    S_total=math.pi*r_outer**2
    
    # r_fly -> 0
    r_inner=r_outer-thickness-r_fly
    gap-=2*r_fly
    r_str+=r_fly
   # print r_inner,gap,r_str

    def is_inside(x,y):
        return (x**2+y**2<=r_inner**2)
    
    def isect(x):
        return math.sqrt(r_inner**2-x**2)
    
    if gap<=0 or r_inner<=0 or r_str>=r_inner:
        S_alive=0
    else: # only consider 1/4
        S_alive=0
        
        n_pre=int(r_inner/(2*r_str+gap))+2 # just in case
        for iy in range(n_pre):
            for ix in range(n_pre):
                # vertices
                x0=r_str+ix*(2*r_str+gap)
                y0=r_str+iy*(2*r_str+gap)
                x1=x0+gap
                y1=y0+gap
                
                v0=is_inside(x0,y0)
                vx=is_inside(x1,y0)
                vy=is_inside(x0,y1)
                vd=is_inside(x1,y1)
                
                if not v0:
                    S_delta=0
                else:
                    if vd:
                        assert vx and vy
                        S_delta=gap**2
                    elif vx and vy:
                        angle=math.atan2(y1,isect(y1))-math.atan2(isect(x1),x1)
                        
                        S_fan=0.5*(r_inner**2)*angle
                        S_tr0=0.5*(y1-isect(x1))*x1
                        S_tr1=0.5*(x1-isect(y1))*y1
                        assert S_fan>0 and S_tr0>0 and S_tr1>0
                        
                        S_delta=gap**2-(S_tr0+S_tr1-S_fan)
                    elif vx:
                        angle=math.atan2(isect(x0),x0)-math.atan2(isect(x1),x1)
                        
                        S_fan=0.5*(r_inner**2)*angle
                        S_tr0=0.5*(isect(x1)-y0)*(x1)
                        S_tr1=0.5*gap*y0
                        S_tr2=0.5*x0*(isect(x0)-y0)
                        assert S_fan>0 and S_tr0>0 and S_tr1>0 and S_tr2>0  
                                              
                        S_delta=S_fan+S_tr0-(S_tr1+S_tr2)
                    elif vy:
                        angle=math.atan2(y1,isect(y1))-math.atan2(y0,isect(y0))
                        
                        S_fan=0.5*(r_inner**2)*angle
                        S_tr0=0.5*(isect(y1)-x0)*(y1)
                        S_tr1=0.5*gap*x0
                        S_tr2=0.5*y0*(isect(y0)-x0)
                        assert S_fan>0 and S_tr0>0 and S_tr1>0 and S_tr2>0  
                                              
                        S_delta=S_fan+S_tr0-(S_tr1+S_tr2)                  
                    else:
                        angle=math.atan2(isect(x0),x0)-math.atan2(y0,isect(y0))
                        
                        S_fan=0.5*(r_inner**2)*angle
                        S_tr0=0.5*(isect(y0)-x0)*y0
                        S_tr1=0.5*(isect(x0)-y0)*x0
                        assert S_fan>0 and S_tr0>0 and S_tr1>0
                        
                        S_delta=S_fan-(S_tr0+S_tr1)
                
                S_alive+=S_delta
            
        S_alive*=4
    
    # 
    return '%.6f'%(1-S_alive/S_total)
    
    
    
def proc_all():
    n_case=int(sys.stdin.readline().rstrip())
    for i in range(n_case):
        print 'Case #%d: %s'%(i+1,proc_case())

proc_all()
    

