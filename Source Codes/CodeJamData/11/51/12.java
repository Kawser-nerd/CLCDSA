import java.io.*;
import java.util.*;

public class BaiA {
	
	static int L, U, G;
	static double W;
	static double[] xl, yl, xu, yu;
	final static double eps = 1e-8;
	
	static double calc(double X, int n, double[] x, double[] y) {
		double x0 = 0, y0 = 0;
		double total = 0;
		ArrayList<Double> lx = new ArrayList<Double>();
		ArrayList<Double> ly = new ArrayList<Double>();
		lx.add(0.0); ly.add(-2000.0);
		for(int i=0;i<n;++i) {
			if(x[i] > X + eps) {
				double Y = (X - x[i-1]) * (y[i] - y[i-1]) / (x[i] - x[i-1]) + y[i-1];
				lx.add(X); ly.add(Y);
				break;
			}
			else {
				lx.add(x[i]); ly.add(y[i]);
			}
		}
		lx.add(X); ly.add(-2000.0);
		x0 = lx.get(lx.size()-1);
		y0 = ly.get(ly.size()-1);
		for(int i=0;i<lx.size();++i) {
			double xx = lx.get(i);
			double yy = ly.get(i);
			total += (x0+xx) * (y0-yy);
			x0 = xx; y0 = yy;
		}
		return Math.abs(total) / 2;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		PrintWriter pw = new PrintWriter(new FileWriter("Alarge.out"));
		
		int ntest = sc.nextInt();
		for(int test=1;test<=ntest;++test) {
			
			W = sc.nextDouble();
			L = sc.nextInt();
			U = sc.nextInt();
			G = sc.nextInt();
			
			xl = new double[L];
			yl = new double[L];
			xu = new double[U];
			yu = new double[U];
			
			for(int i=0;i<L;++i) {
				xl[i] = sc.nextDouble();
				yl[i] = sc.nextDouble();
			}
			
			for(int i=0;i<U;++i) {
				xu[i] = sc.nextDouble();
				yu[i] = sc.nextDouble();
			}
			
			double S = -(calc(W, L, xl, yl) - calc(W, U, xu, yu)) / G;
			
			// System.out.println(S);
			
			pw.println("Case #" + test + ":");

			for(int i=0;i+1<G;++i) {
				double low = 0, high = W;
				for(int kk=0;kk<77;++kk) {
					double mid = (low + high) / 2;
					double SS = (calc(mid, U, xu, yu) - calc(mid, L, xl, yl));
					if(SS < S * (i+1)) low = mid;
					else high = mid;
				}
				pw.printf("%.8f\n", low);
			}
			
						
			// pw.println();
			
		}
		
		sc.close();
		pw.close();
	}
}
