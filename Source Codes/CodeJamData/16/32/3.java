package gcj2016r1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class ProblemB {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ProblemB obj = new ProblemB();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str, " ");
			int B = Integer.parseInt(token.nextToken());
			long M = Long.parseLong(token.nextToken());

			boolean[][] mtx = new boolean[B][B];
			for (int j = 1; j < B - 1; j++) {
				for (int k = 0; k < j; k++) {
					mtx[k][j] = true;
				}
			}

			for (int j = 0; j < B - 2; j++) {
				if (M >= (1L << (B - j - 3))) {
					mtx[B - j - 2][B - 1] = true;
					M -= (1L << (B - j - 3));
				}
			}
			if (M >= 1) {
				mtx[0][B - 1] = true;
				M -= 1;
			}
			if (M == 0) {
				bw.write("Case #" + (i + 1) + ": " + "POSSIBLE");
				bw.write("\r\n");
				for (int j = 0; j < B; j++) {
					for (int k = 0; k < B; k++) {
						bw.write(mtx[j][k] ? '1' : '0');
					}
					bw.write("\r\n");
				}
			} else {
				bw.write("Case #" + (i + 1) + ": " + "IMPOSSIBLE");
				bw.write("\r\n");
			}
		}
		bw.close();
		br.close();
	}
}
