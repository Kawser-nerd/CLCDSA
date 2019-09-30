import java.util.*;
public class Main {
	public static void main(String[] args) {
		long inf = (long) Math.pow(10, 11);
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int Q = sc.nextInt();
		long[] s = new long[A+2];
		s[0] = -inf;
		s[A+1] = inf;
		for(int i = 1; i < A+1; i++) s[i] = sc.nextLong();
		long[] t = new long[B+2];
		t[0] = -inf;
		t[B+1] = inf;
		for(int i = 1; i < B+1; i++) t[i] = sc.nextLong();
		long[] x = new long[Q];
		for(int i = 0; i < Q; i++) x[i] = sc.nextLong();
		for(int i = 0; i < Q; i++) {
			int b = Math.abs(Arrays.binarySearch(s, x[i])) - 1;
			int d = Math.abs(Arrays.binarySearch(t, x[i])) - 1;
			long res = inf;
			for(int j = b-1; j <= b; j++) {
				for(int k = d-1; k <= d; k++) {
					long d1 = Math.abs(s[j]-x[i]) + Math.abs(s[j]-t[k]);
					long d2 = Math.abs(t[k]-x[i]) + Math.abs(s[j]-t[k]);
					res = Math.min(res,  Math.min(d1, d2));
				}
			}
			System.out.println(res);
		}
	}

}