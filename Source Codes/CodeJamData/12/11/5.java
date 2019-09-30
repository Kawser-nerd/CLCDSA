import java.util.*;
import static java.lang.Math.*;

public class A {
	static void p(Object ...o) { System.out.println(Arrays.deepToString(o));}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int zz = 1; zz <= T; zz++) {
			int A = in.nextInt();
			int B = in.nextInt();
			double[] P = new double[A];
			for(int i = 0; i < A; i++)
				P[i] = in.nextDouble();
			
			double ans = B + 2;
			double p = 1.0;
			for (int l = 0; l <= A; l++) {
				double a1 = (A-l) + (B-l) + 1;
				double a2 = (A-l) + (B-l) + 1 + B + 1;
				ans = min(ans, p*a1 + (1-p)*a2);
				if (l < A)
					p *= P[l];
			}
			System.out.format("Case #%d: %.09f\n", zz, ans);
		}
	}
}
