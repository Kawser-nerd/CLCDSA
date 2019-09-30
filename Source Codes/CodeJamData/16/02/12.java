import java.io.*;

public class B {
	static int count(char[] cc) {
		int n = cc.length;
		int cnt = cc[n - 1] == '-' ? 1 : 0;
		for (int i = 1; i < n; i++)
			if (cc[i] != cc[i - 1])
				cnt++;
		return cnt;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			char[] cc = br.readLine().toCharArray();
			pw.println("Case #" + t + ": " + count(cc));
		}
		pw.close();
	}
}
