package centerofmass;

import java.io.IOException;

public class Main extends Base {
    long N;
    
    double vx;
    double vy;
    double vz;

    double x;
    double y;
    double z;
    
    public static void main(String[] args) throws IOException {
        Main m = new Main();
        m.run("B", "large");        
    }

    @Override
    void init() {
        
    }

    @Override
    void load() throws IOException {
        N = Long.parseLong(br.readLine());
        
        double sx, sy, sz;
        double svx, svy, svz;        

        sx = 0; sy = 0; sz = 0;
        svx = 0; svy = 0; svz = 0;
        for (int i = 0; i < N; i++) {
            String s[] = br.readLine().split(" ");
            long curx = Long.parseLong(s[0]);
            long cury = Long.parseLong(s[1]);
            long curz = Long.parseLong(s[2]);
            
            long curvx = Long.parseLong(s[3]);
            long curvy = Long.parseLong(s[4]);
            long curvz = Long.parseLong(s[5]);
            
            sx += curx; sy += cury; sz += curz;
            svx += curvx; svy += curvy; svz += curvz;
        }
        
        vx = svx / (double) N;
        vy = svy / (double) N;
        vz = svz / (double) N;
        
        x = sx / (double) N;
        y = sy / (double) N;
        z = sz / (double) N;
             
        System.out.println("Case: "+caseId);
        System.out.println("START   : "+x+" "+y+" "+z);
        System.out.println("VELOCITY: "+vx+" "+vy+" "+vz);
    }

    @Override
    void solve() {

        double xlen = Math.sqrt(x*x+y*y+z*z);
        double vlen = Math.sqrt(vx*vx+vy*vy+vz*vz);
        vx /= vlen; vy /= vlen; vz /= vlen;
        
        //System.out.println("VELOCITY: "+vx+" "+vy+" "+vz+" "+(vx*vx+vy*vy+vz*vz));
        if (vlen <= Double.MIN_VALUE*100) {
            printResult(String.format("%1$.8f %2$.8f", xlen, 0.0));
            return;
        }
        
        
        
        if (xlen <= 0.0000000000001) {
            //printResult("0.0 0.0");
            printResult(String.format("%1$.8f %2$.8f", 0.0, 0.0));
            return;
        }
        
        double cosAxlen = (vx*x+vy*y+vz*z); //xlen   (xlen > 0)
        double cosA = cosAxlen / xlen;
        if (cosA >= 0) {
            System.out.println("SPECIAL CASE 1");
            printResult(String.format("%1$.8f %2$.8f", xlen, 0.0));
            return;
        }
        
        double bx = vx*cosAxlen;
        double by = vy*cosAxlen;
        double bz = vz*cosAxlen;
        
        double cx = x-bx;
        double cy = y-by;
        double cz = z-bz;
        
        double result = Math.sqrt(cx*cx+cy*cy+cz*cz);
        double t = Math.sqrt(bx*bx+by*by+bz*bz)/vlen;
        printResult(String.format("%1$.8f %2$.8f", result, t));
    }

}
