import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemD {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int N = in.nextInt();
			double[] a = new double[N];
			double[] b = new double[N];
			for (int i = 0 ; i < N ; i++) {
				a[i] = in.nextDouble();
			}
			for (int i = 0 ; i < N ; i++) {
				b[i] = in.nextDouble();
			}
			int[] res = solve(a, b);
			out.println(String.format("Case #%d: %d %d", cn, res[0], res[1]));
		}
		out.flush();
	}
	
	private static int[] solve(double[] a, double[] b) {
		int n = a.length;
		Arrays.sort(a);
		Arrays.sort(b);
		
		int[] res = new int[2];
		
		{
			// deceived
			int bh = 0;
			for (int i = 0 ; i < n ; i++) {
				if (a[i] > b[bh]) {
					res[0]++;
					bh++;
				}
			}
		}
		
		{
			// normal
 			boolean[] used = new boolean[n];
			for (int i = 0 ; i < n ; i++) {
				boolean willLose = false;
				for (int j = 0 ; j < n ; j++) {
					if (used[j]) {
						continue;
					}
					if (a[i] < b[j]) {
						used[j] = true;
						willLose = true;
						break;
 					}
				}
				if (!willLose) {
					for (int j = 0 ; j < n ; j++) {
						if (used[j]) {
							continue;
						}
						used[j] = true;
						break;
					}
					res[1]++;					
				}
			}
		}
		res[0] = Math.max(res[0], res[1]);
		return res;
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
