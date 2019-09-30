package Rnd1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("output.txt"));
		int max = 1000020;
		int t = in.nextInt();
		for (int m = 1; m <= t; m++) {
			int A = in.nextInt();
			int n = in.nextInt();
			int[] M = new int[n];
			for (int i = 0; i < n; i++)
				M[i] = in.nextInt();
			Arrays.sort(M);
			int[][] DP = new int[2][max];
			for (int i = n - 1; i >= 0; i--)
				for (int j = max - 1; j > 0; j--) {
					DP[i & 1][j] = DP[1 - (i & 1)][j] + 1;
					if (j > M[i]) {
						int newSize = Math.min(j + M[i], max - 1);
						DP[i & 1][j] = Math.min(DP[i & 1][j],
								DP[1 - (i & 1)][newSize]);
					}
					int next = Math.min(j + j - 1, max - 1);
					DP[i & 1][j] = Math.min(DP[i & 1][j], DP[i & 1][next] + 1);
				}
			out.println("Case #" + m + ": " + DP[0][A]);
		}
		out.flush();
		out.close();
	}
}
