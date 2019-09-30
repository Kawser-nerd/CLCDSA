import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class P3 {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner s = new Scanner(new FileInputStream("C-large.in"));

		int cnt = s.nextInt();

		int d[];
		int f[][];

		for (int cases = 0; cases < cnt; cases++) {
			int n = s.nextInt();
			int p = s.nextInt();
			d = new int[p + 2];
			for (int i = 1; i < p + 1; i++) {
				d[i] = s.nextInt();
			}
			d[p + 1] = n+1;

			f = new int[p + 1][p + 2];

			for (int j = 2; j <= p + 1; j++) {
				for (int i = 0; i + j <= p + 1; i++) {
					int min = 100000000;
					for (int k = 1; k < j; k++) {
						if (min > f[i][k] + f[i + k][j - k] + d[j + i] - d[i]
								- 2) {
							min = f[i][k] + f[i + k][j - k] + d[j + i] - d[i]
									- 2;
						}
					}
					f[i][j] = min;
				}
			}

			System.out.println("Case #" + (cases + 1) + ": " + f[0][p + 1]);
		}
	}
}
