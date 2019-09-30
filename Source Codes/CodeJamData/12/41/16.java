import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("A.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int n = in.nextInt();
			int[][] v = new int[n][];
			for (int i = 0; i < n; i++) {
				v[i] = new int[]{in.nextInt(), in.nextInt()};
			}
			int d = in.nextInt();
			
			Arrays.sort(v, new Comparator<int[]>(){
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			
			int[] r = new int[n];
			Arrays.fill(r, Integer.MIN_VALUE);
			r[0] = v[0][0];
			
			for (int i = 0; i < n; i++) {
				int reach = v[i][0] + r[i];
				for (int j = i+1; j < n && v[j][0] <= reach; j++) {
					r[j] = Math.max(r[j], Math.min(v[j][1], v[j][0] - v[i][0]));
				}
			}
			
			boolean good = false;
			for (int i = 0; i < n; i++) {
				good |= v[i][0] + r[i] >= d;
			}
			
			out.println(good ? "YES" : "NO");
		}
		
		out.flush();
	}

}
