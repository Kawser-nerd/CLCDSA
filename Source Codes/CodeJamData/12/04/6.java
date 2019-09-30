import java.util.Scanner;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("D-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("gcj4.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		GCJ4 solver = new GCJ4();
		solver.solve(1, in, out);
		out.close();
	}
}

class GCJ4 {
    int[] DX = {1,1,-1,-1};
    int[] DY = {1,-1,1,-1};
    double EPS = 1e-9;
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        int cases = in.nextInt();
        for(int caseNum =0;caseNum<cases;caseNum++) {
            int res = 0;
            int I = in.nextInt();
            int J = in.nextInt();
            int D = in.nextInt();
            int SX = -1;
            int SY = -1;
            in.nextLine();
            String[] m = new String[I];
            for(int i=0;i<I;i++) {
                m[i] = in.nextLine();
                for(int j=0;j<J;j++) {
                    if(m[i].charAt(j)=='X') {
                        SX = j;
                        SY = i;
                    }
                }
            }
            for(int y=0;y<=50;y++) {
                for(int x=0;x<=50;x++) {
                    next_try: for(int k=0;k<4;k++) {
                        if(x==0 && y==0)continue;
                        if(IntLib.gcd(x,y)>1)continue;
                        int dx = DX[k];
                        int dy = DY[k];
                        if(dx==-1 && x==0 || dy==-1 && y==0)continue;
                        if(x==0)dx=0;
                        if(y==0)dy=0;
                        double dist = 0;
                        int curX = SX;
                        int curY = SY;
                        int ddx = 0;
                        int ddy = 0;
                        //debug("NEXT",x,y);
                        while(ddx*ddx+ddy*ddy<=D*D) {
                            //if(x==3 && y==7)debug(ddx,ddy);
                            boolean goRight = false;
                            boolean goUp = false;
                            if(y==0)goRight = true;
                            else if(x==0)goUp = true;
                            else {
                                int minAnchor = Math.min(ddx/x,ddy/y);
                                int fromAnchorX = ddx-x*minAnchor;
                                int fromAnchorY = ddy-y*minAnchor;
                                if(x%2==1 && y%2==1 && fromAnchorX==(x+1)/2-1 && fromAnchorY==(y+1)/2-1) {
                                    goRight = goUp = true;
                                }
                                else {
                                    if(GeomLib.cross2D(0.,0.,x,y,ddx+.5,ddy+.5)>0) {
                                        goRight = true;
                                    }
                                    else goUp = true;
                                }
                            }
                            int nextX = curX;
                            int nextY = curY;
                            if(goRight) {
                                nextX+=dx;
                            }
                            if(goUp) {
                                nextY+=dy;
                            }
                            if(m[nextY].charAt(nextX)=='#') {
                                if(goUp && goRight) {
                                    if(m[curY].charAt(nextX)=='#' && m[nextY].charAt(curX)=='#') {
                                        int ma = Math.min(ddx/x,ddy/y);
                                        double fx = x*ma;
                                        double fy = y*ma;
                                        double smx = x*.5;
                                        double smy = y*.5;
                                        if(Math.sqrt(fx*fx+fy*fy)+Math.sqrt(smx*smx+smy*smy)-EPS<D*.5) {
                                            //debug("CORNER",x*DX[k],y*DY[k],curX,curY);
                                            res++;
                                        }
                                        continue next_try;
                                    }
                                    else if(m[curY].charAt(nextX)=='#') {
                                        nextX -=dx;
                                        dx=-dx;
                                    }
                                    else if(m[nextY].charAt(curX)=='#') {
                                        nextY -= dy;
                                        dy=-dy;
                                    }
                                    else continue next_try;//lost ray
                                }
                                else if (goUp) {
                                    if(x==0) {
                                        if(Math.abs(SY-nextY)*2-1<=D) {
                                            //debug("VER REFLECT",x*DX[k],y*DY[k]);
                                            res++;
                                        }
                                        continue next_try;
                                    }
                                    nextY-=dy;
                                    dy=-dy;
                                }
                                else if (goRight) {
                                    if(y==0) {
                                        if(Math.abs(SX-nextX)*2-1<=D) {
                                            //debug("HOR REFLECT",x*DX[k],y*DY[k]);
                                            res++;
                                        }
                                        continue next_try;
                                    }
                                    nextX-=dx;
                                    dx=-dx;
                                }
                                else throw new RuntimeException();
                            }

                            if(goRight) {
                                ddx++;
                            }
                            if(goUp) {
                                ddy++;
                            }

                            if(nextY == SY && nextX == SX) {
                                int ma = Math.min(ddx/x,ddy/y);
                                if(ddx==ma*x && ddy==ma*y) {
                                    if(ddx*ddx +ddy*ddy <=D*D) {
                                        //debug("BOUNCY",x*DX[k],y*DY[k]);
                                        res++;
                                    }
                                    continue next_try;
                                }
                            }
                            curX = nextX;
                            curY = nextY;
                        }
                    }
                }
            }
            
            out.println("Case #"+(caseNum+1)+": "+res);
            debug("Case #"+(caseNum+1)+": ",m);
        }
	}
    void debug(Object...os) {
    // BEGIN CUT HERE
        System.out.println(Arrays.deepToString(os));
    // END CUT HERE
    }
}

class IntLib {
    public static int gcd(int a, int b) {
        if(b==0)return a;
        else return gcd(b,a%b);
    }
    }

class GeomLib {
    public static double cross2D(double ax, double ay, double bx, double by, double cx, double cy) {
        double abx = bx-ax;
        double aby = by-ay;
        double acx = cx-bx;
        double acy = cy-by;
        return abx*acy - aby*acx;
    }
}

