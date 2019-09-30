package gcj2009.qual;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	static final int INF = 1 << 20;
	static final int[] di = { -1, 0, 0, 1 };
	static final int[] dj = { 0, -1, 1, 0 };
	static final char[] key = "welcome to code jam".toCharArray();
	static final int mod = 10000;

	public void run() {
		char[] input = sc.nextLine().toCharArray();
		int[] dp = new int[key.length + 1];
		dp[0] = 1;
		for(char c : input)
			for(int i = key.length - 1; i >= 0; i--)
				if(key[i] == c)
					dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
		System.out.printf("%04d%n", dp[key.length]);
	}

	public static void main(String...args) {
		try { 
			System.setIn(new FileInputStream("C-large.in"));
			System.setOut(new PrintStream("C-large.out"));
		} catch(Exception e) {}
		sc = new Scanner(System.in);
		int T = sc.nextInt(); sc.nextLine();
		for(int t = 1; t <= T; t++) {
			System.out.printf("Case #%d: ", t);
			new C().run();
		}
	}

	static Scanner sc;
}
