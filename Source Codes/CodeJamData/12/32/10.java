import java.io.*;
import java.util.*;


public class B {
	
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B-small.out"));
		int T = Integer.parseInt(in.readLine());
		for(int i=0; i<T; i++) {
			String s = in.readLine();
			String[] ss = s.split(" ");
			double D = Double.parseDouble(ss[0]);
			int N = Integer.parseInt(ss[1]);
			int A = Integer.parseInt(ss[2]);
			double[] t = new double[N];
			double[] x = new double[N];
			double[] a = new double[A];
			for(int j=0; j<N; j++) {
				s = in.readLine();
				ss = s.split(" ");
				t[j] = Double.parseDouble(ss[0]);
				x[j] = Double.parseDouble(ss[1]);
			}
			out.println("Case #"+(i+1)+":");
			s = in.readLine();
			ss = s.split(" ");
			for(int j=0; j<A; j++) {
				a[j] = Double.parseDouble(ss[j]);
				
				double ans = Math.sqrt(2/a[j]*D);
				int k=0;
				for(; k<N; k++) {
					if(x[k]>=D) break;
					double ti = t[k]-Math.sqrt(x[k]*2/a[j]);
					ans = Math.max(ans, Math.sqrt(2/a[j]*D)+ti);
				}
				
				if(k>0) {
					double f = (D-x[k-1])/(x[k]-x[k-1]);
					double te = f*(t[k]-t[k-1])+t[k-1];
					ans = Math.max(ans, te);
				}
				
				
				out.println(ans);
			}
			
			
			
		}
		out.close();
	}
}
