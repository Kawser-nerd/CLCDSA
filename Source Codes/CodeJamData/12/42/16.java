import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int n = in.nextInt(), w = in.nextInt(), l = in.nextInt();
			int[][] r = new int[n][];
			for (int i = 0; i < n; i++) r[i] = new int[]{in.nextInt(), i};
			Arrays.sort(r, new Comparator<int[]>(){
				public int compare(int[] a, int[] b) {
					return b[0] - a[0];
				}
			});
			
			double[] x = new double[n];
			double[] y = new double[n];
			x[r[0][1]] = 0;
			y[r[0][1]] = 0;
			double curX = 0, curY = 0, prevR = r[0][0], dx = r[0][0];
			for (int j = 1; j < n; j++) {
				int ind = r[j][1];
				double nextY = curY + prevR + r[j][0];
				if (nextY - 1e-9 <= l) {
					x[ind] = curX;
					y[ind] = nextY;
					curY = nextY;
					prevR = r[j][0];
				}
				else {
					double nextX = curX + dx + r[j][0];
					x[ind] = nextX;
					y[ind] = 0;
					curX = nextX;
					curY = 0;
					prevR = r[j][0];
					dx = r[j][0];
				}
				
				if (curX - 1e-9 > w) throw new RuntimeException();
			}
			
			for (int i = 0; i < n; i++) {
				out.print(String.format(Locale.US, "%.1f %.1f ", x[i], y[i]));
			}
			out.println();
		}
		
		out.flush();
	}

}
