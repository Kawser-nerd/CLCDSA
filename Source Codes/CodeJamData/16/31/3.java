package gcj2016r1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ProblemA obj = new ProblemA();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			int N = Integer.parseInt(br.readLine());
			int[] P = new int[N];

			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str, " ");

			int cnt = 0;
			for (int j = 0; j < N; j++) {
				P[j] = Integer.parseInt(token.nextToken());
				cnt += P[j];
			}

			StringBuffer buf = new StringBuffer();

			while (cnt > 0) {
				int max_j = -1;
				int max = 0;
				for (int j = 0; j < N; j++) {
					if (P[j] > max) {
						max_j = j;
						max = P[j];
					}
				}
				P[max_j]--;
				cnt--;
				buf.append((char)('A' + max_j));
				
				if (cnt <= 0) {
					break;
				}
				if (cnt == 2) {
					buf.append(' ');
					continue;
				}
				
				max_j = -1;
				max = 0;
				for (int j = 0; j < N; j++) {
					if (P[j] > max) {
						max_j = j;
						max = P[j];
					}
				}
				P[max_j]--;
				cnt--;
				buf.append((char)('A' + max_j));
				
				if (cnt > 0) {
					buf.append(' ');
				}
			}

			bw.write("Case #" + (i + 1) + ": " + buf.toString());
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
