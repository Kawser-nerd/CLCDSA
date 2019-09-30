package codejam15;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(new File("b.in")));
		PrintWriter pw = new PrintWriter("b.out");

		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {

			int d = sc.nextInt();
			int c[] = new int[d];
			for (int i = 0; i < d; i++)
				c[i] = sc.nextInt();
			int ans = Integer.MAX_VALUE;
			for (int i = 1; i < 1100; i++) {
				int add = 0;
				for (int j : c) {
					int q = j / i + (j % i == 0 ? 0 : 1);
					add += q - 1;
				}
				ans = Math.min(ans, add + i);
			}

			pw.printf("Case #%d: %d\n", t, ans);
		}
		sc.close();
		pw.close();
	}

	private static int max(int[] c, int i) {
		while (i > 0 && c[i] == 0)
			i--;
		return i;
	}

}
