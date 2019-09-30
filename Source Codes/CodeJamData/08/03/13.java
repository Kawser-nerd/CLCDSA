import java.util.*;
import java.io.*;

class CodeJam {
	static public void main(String []args) {
		long time1 = (new Date()).getTime();
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		
		int N = parseInt(nextline(inp));
		for (int caseidx = 0; caseidx < N; caseidx++) {
			String line = nextline(inp);
			StringTokenizer tok = new StringTokenizer(line);
			double f = parseDouble(tok.nextToken());
			double R = parseDouble(tok.nextToken());
			double t = parseDouble(tok.nextToken());
			double r = parseDouble(tok.nextToken());
			double g = parseDouble(tok.nextToken());
			
			t += f;
			r += f;
			g -= (2*f);
			
			System.err.println("g:" + g + " R:"+R);
			
			double iR = R-t;
			double ss = 2*r+g;
			
			double openarea = 0;
			if (g > 0.000000001) {
				for (double x = r; x < iR; x += ss) {
					for (double y = r; y < iR; y += ss) {
						openarea += calc(x, y, iR);
						openarea += calc(x+g, y+g, iR);
						openarea -= calc(x+g, y, iR);
						openarea -= calc(x, y+g, iR);
					}
				}
			}
			double totalarea = calc(0, 0, R);
			System.err.println("open:"+openarea+" total:"+totalarea);
			
			System.out.println("Case #"+(caseidx+1)+": "+((totalarea-openarea)/totalarea));
		}
		
		long time2 = (new Date()).getTime();
		
		System.err.println("Time taken: "+(time2-time1));
		System.out.flush();
	}
	
	static double calc(double x, double y, double r) {
		if (x*x + y*y > r*r) return 0;
		double cir = Math.PI*r*r;
		double qcir = cir/4;
		double xa = Math.asin(y/r);
		double ya = Math.asin(x/r);
		double xcir = cir*xa/(Math.PI*2) + (y*r*Math.cos(xa)/2);
		double ycir = cir*ya/(Math.PI*2) + (x*r*Math.cos(ya)/2);
		double tot = qcir + x*y - xcir - ycir;
		
//		System.err.println("qcir:"+qcir+" sq:"+(x*y)+" xc:"+xcir+" yc:"+ycir);
//		System.err.println("x:"+x+" y:"+y+" r:"+r+" tot:"+tot);
		return tot;
	}
	
	static public String nextline(BufferedReader inp) {
		String line = "";
		try { line = inp.readLine(); } catch (Exception e) {}
		return line;
	}
		
	static public int parseInt(String line) {
		int ret = 0;
		try { ret = Integer.parseInt(line); } catch (Exception e) {}
		return ret;
	}
		
	static public double parseDouble(String line) {
		double ret = 0;
		try { ret = Double.parseDouble(line); } catch (Exception e) {}
		return ret;
	}
}
