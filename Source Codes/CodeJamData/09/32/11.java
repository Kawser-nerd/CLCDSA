import java.io.*;
import java.util.*;

public class Main {

	Scanner in;
	PrintWriter out;
	
	
	final double EPS = 1e-8;
	
	void run() throws IOException {
		Locale.setDefault(Locale.US);
		in = new Scanner(new File("small.in"));
		out = new PrintWriter("small.out");
		
		int test = in.nextInt();
		for (int nt = 1; nt <= test; nt++) {
			int n = in.nextInt();
			
			double[] sumcoord = new double[3];
			double[] sumv = new double[3];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 3; j++) {
					double q = in.nextDouble();
					sumcoord[j] += q;
				}
				for (int j = 0; j < 3; j++) {
					double q = in.nextDouble();
					sumv[j] += q;
				}
			}
			
			double a = 0.0d;
			for (int j = 0; j < 3; j++)
				a += sumv[j]*sumv[j];
			
			double b = 0.0d;
			for (int j = 0; j < 3; j++)
				b += 2.0d*sumcoord[j]*sumv[j];
			
			double c = 0.0d;
			for (int j = 0; j < 3; j++)
				c += sumcoord[j]*sumcoord[j];
			
			
			double ret = 0.0d;
			double dist0 = c;
						
			if (Math.abs(a) >= EPS) {
				double t = -b / (2*a);
				if (t > -EPS) {
					double dist = a*t*t + b*t + c;
					if (dist < dist0-EPS) {
						ret = t;
					}						
				}
			}				
			
			double retDist = Math.sqrt(a*ret*ret + b*ret + c) / n;
			out.print("Case #" + nt + ": ");
			out.printf("%.8f", retDist);
			out.print(" ");
			out.printf("%.8f\n", ret);
		}
						
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
}
