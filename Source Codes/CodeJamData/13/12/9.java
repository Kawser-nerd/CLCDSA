import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {
		String path = "D:\\B-large";
		Scanner sc = new Scanner(new File(path + ".in"));
		PrintWriter pw = new PrintWriter(path + ".out");
		int testCases = sc.nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			long E = sc.nextInt();
			long R = sc.nextInt();
			int n = sc.nextInt();
			long[] v = new long[n];
			for (int i = 0; i < n; i++) {
				v[i] = sc.nextInt();
			}
			long res = 0;
			long energy = E;
			for (int i = 0; i < n; i++) {
				long cur = energy;
				for (int j = i + 1; j < n; j++) {
					if (v[j] > v[i]) {
						long d = j - i;
						long regeneration = d * R;
						long y = regeneration - (E - energy);
						cur = Math.min(y, energy);
						cur = Math.max(cur, 0);
						break;
					}
				}
				res += cur * v[i];
				energy = Math.min(energy - cur + R, E);
			}

			pw.println("Case #" + testCase + ": " + res);
			pw.flush();
		}
		pw.close();
	}
}
