import java.util.*;
import java.io.*;

public class B {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		double D;
		int N, A;
		
		for(int caseNo =1; caseNo <=T;caseNo++) {
			D = in.nextDouble(); N = in.nextInt(); A = in.nextInt();
			double anotherVelocity;
			double[] t = new double[N];
			double[] x = new double[N];
			double minTime = 0;
			
			for(int i=0; i<N; i++) {
				t[i] = in.nextDouble();
				x[i] = in.nextDouble();
			}
			
			if (N == 2) {
				anotherVelocity = (x[1] - x[0]) / (t[1] - t[0]);
				minTime = (D - x[0]) / anotherVelocity + t[0];
			}				
			
			System.out.println("Case #"+caseNo+":");
			for(int i=0;i<A;i++) {
				double a = in.nextDouble();
				if (N == 1) {
					System.out.printf("%.7f\n", Math.sqrt(2 * D / a));
				} else {
					System.out.printf("%.7f\n", Math.max(Math.sqrt(2 * D / a), minTime));
				}
			}
		}
	}
}