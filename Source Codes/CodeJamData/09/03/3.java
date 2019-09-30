import java.io.*;
import java.util.*;


public class Solution {

	public static BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer tok = null;
	
	public static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(cin.readLine());
		}
		return tok.nextToken();
	}
	
	public static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	
	public static final String CodeJam = "welcome to code jam";
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int N = nextInt();
		for (int i = 0; i < N; i++) {
			String s = cin.readLine();
			int L = s.length();
			int[][] ans = new int[L + 1][20];
			ans[0][0] = 1;
			for (int j = 1; j <= L; j++) {
				//ans[j][0] = 1;
				for (int k = 0; k < 19; k++)
					if (CodeJam.charAt(k) == s.charAt(j - 1)) {
						for (int m = 0; m < j; m++)
							ans[j][k + 1] = (ans[j][k + 1] + ans[m][k]) % 10000;
					}
			}
			int sum = 0;
			for (int j = 0; j <= L; j++)
				sum = (sum + ans[j][19]) % 10000;
			System.out.println("Case #" + (i + 1) + ": " + (sum < 1000 ? "0" : "") + (sum < 100 ? "0" : "") + (sum < 10 ? "0" : "") + sum);
		}

	}

}
