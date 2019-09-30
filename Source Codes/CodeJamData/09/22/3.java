import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	public static void main(String args[]) throws Exception {
		in = new BufferedReader(new InputStreamReader(new FileInputStream("b.in")));
		out = new PrintWriter(new OutputStreamWriter(new FileOutputStream("b.out")));
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			String n = "0" + next();
			int cnts[] = new int[10];
//			for (int i = 0; i < n.length(); i++) {
//				cnts[n.charAt(i) - '0']++;
//			}
			String ans;
			PLoop:
			for (int p = n.length() - 1; ; p--) {
				int c = n.charAt(p) - '0';
				++cnts[c];
				for (int nc = c + 1; nc < 10; ++nc) {
					if (cnts[nc] > 0) {
						StringBuilder sb = new StringBuilder();
						sb.append(n.substring(0, p));
						sb.append((char) ('0' + nc));
						--cnts[nc];
						for (int i = 0; i < 10; ++i) {
							while (cnts[i] > 0) {
								sb.append((char) ('0' + i));
								--cnts[i];
							}
						}
						ans = sb.toString();
						break PLoop;
					}
				}
				if (p == 0) {
					throw new AssertionError();
				}
			}
			out.println("Case #" + (t + 1) + ": " + new BigInteger(ans).toString());
		}
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
}