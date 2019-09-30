import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class C {
	

	private static final int mod = 100003;

	Object solve() {
		int n = sc.nextInt();
		
		long[][] dp = new long[n+1][n+1];
		
		dp[1][0] = 1;
		for (int last = 1; last <= n; last++) {
			for (int pos = 0; pos <= n; pos++) {
				if (dp[last][pos] == 0) continue;
				for (int next = last + 1; next <= n; next++) {
					dp[next][last] = (dp[next][last] + (nCkP[next - last - 1][last - pos - 1]*dp[last][pos]))%mod;
				}
			}
		}
		
		long res = 0;
		for (int i = 0; i <= n; i++)
			res = (res + dp[n][i])%mod;
		
		return res;
	}
	
	private static long[][] nCkP = new long[505][505];

	private static void prepnCkP() {
		for (int i = 0; i < 505; i++) {
			nCkP[i][0] = nCkP[i][i] = 1;
			for (int j = 1; j <= i/2; j++) {
				nCkP[i][j] = nCkP[i][i-j] = (nCkP[i-1][j-1] + nCkP[i-1][j])%mod;
			}
		}
	}
	
	static {
		prepnCkP();
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "C-small-attempt0.in";
		inFile = "C-large.in";
		
		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new C().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
