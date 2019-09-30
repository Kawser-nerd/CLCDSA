package gcj2016r1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class ProblemC {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ProblemC obj = new ProblemC();
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
			int J = Integer.parseInt(token.nextToken());
			int P = Integer.parseInt(token.nextToken());
			int S = Integer.parseInt(token.nextToken());
			int K = Integer.parseInt(token.nextToken());

			ArrayList<int[]> list = new ArrayList<>();
			int[] chk = new int[P];
			int s = 0;
			for (int j = 0; j < J; j++) {
				for (int p = 0; p < P; p++) {
					if (j != 0) {
						s = chk[p];
					}
					for (int k = 0; k < Math.min(K, S); k++) {
						list.add(new int[] { j + 1, p + 1, s + 1 });
						s = (s + 1) % S;
						chk[p] = s;
					}
				}
			}
			bw.write("Case #" + (i + 1) + ": " + list.size());
			bw.write("\r\n");
			for (int[] e : list) {
				bw.write(e[0] + " " + e[1] + " " + e[2]);
				bw.write("\r\n");
			}
		}
		bw.close();
		br.close();
	}
}
