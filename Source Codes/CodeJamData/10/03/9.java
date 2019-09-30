package qr2010;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ThemePark {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ThemePark obj = new ThemePark();
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
			int R = Integer.parseInt(token.nextToken());
			int k = Integer.parseInt(token.nextToken());
			int N = Integer.parseInt(token.nextToken());

			int[] g = new int[N];
			str = br.readLine();
			token = new StringTokenizer(str, " ");
			for (int n = 0; n < N; n++) {
				g[n] = Integer.parseInt(token.nextToken());
			}

			long[] euro = new long[N];
			int[] idx = new int[N];
			Arrays.fill(euro, -1);
			Arrays.fill(idx, -1);

			long currentEuro = 0;
			int startIdx = 0;
			int runs = 0;
			while (runs < R) {
				idx[startIdx % N] = runs++;
				euro[startIdx % N] = currentEuro;
				long rider = 0;
				int grps = 0;
				for (int m = startIdx; m < startIdx + N; m++) {
					if (rider + g[m % N] <= k) {
						rider += g[m % N];
						grps++;
					} else {
						break;
					}
				}
				currentEuro += rider;
				startIdx += grps;

				if (idx[startIdx % N] != -1) {
					long cycleEuro = currentEuro - euro[startIdx % N];
					int cycle = runs - idx[startIdx % N];
					int cycleCnt = (R - idx[startIdx % N]) / cycle;
					int mod = (R - idx[startIdx % N]) % cycle;
					long modEuro = 0;
					for (int j = 0; j < N; j++) {
						if (mod + idx[startIdx % N] == idx[j]) {
							modEuro = euro[j] - euro[startIdx % N];
						}
					}
					currentEuro = cycleEuro * cycleCnt + euro[startIdx % N]
							+ modEuro;
					break;
				}
			}

			bw.write("Case #" + (i + 1) + ": ");
			bw.write("" + currentEuro);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
