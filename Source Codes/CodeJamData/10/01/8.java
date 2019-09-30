package qr2010;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class SnapperChain {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		SnapperChain obj = new SnapperChain();
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
			int N = Integer.parseInt(token.nextToken());
			int K = Integer.parseInt(token.nextToken());

			bw.write("Case #" + (i + 1) + ": ");
			if ((K & ((1 << N) - 1)) == ((1 << N) - 1)) {
				bw.write("ON");
			} else {
				bw.write("OFF");
			}
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
