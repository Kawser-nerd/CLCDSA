import java.util.*;
public class C {
	static int [] dx = {-1,0,0,1};
	static int [] dy = {0,-1,1,0};
	static int H,W;
	static final String key = "welcome to code jam";
	static final int M = 10000;
	public static void main (String [] arg) throws Throwable {
			int N = nextInt();
			for (int ii = 1; ii<=N; ++ii) {
				String s = nextLine();
				int [][] dp = new int [key.length()][s.length()];
				int ans = 0;
				for (int i = 0; i<s.length(); ++i) {
					if (s.charAt(i) == key.charAt(0)) ans++;
					dp[0][i] = ans;
				}
				for (int j = 1; j<dp.length; ++j) {
					for (int k = 1; k<dp[j].length; ++k) {
						dp[j][k] = dp[j][k-1] % M;
						if (s.charAt(k) == key.charAt(j)) {
							dp[j][k]+=dp[j-1][k-1];
							dp[j][k]=dp[j][k]%M;
						}
					}
				}
				ans = dp[dp.length-1][dp[0].length-1];
				System.out.printf("Case #%d: %04d\n",ii,ans%M);
			}
	}

public static int nextInt() throws Throwable {
		int i = 0;
		boolean negative = false;
		while (i < 44) i = System.in.read();
		if (i == 45) {
			negative = true; i = 0;
		} else {
			 i = i - 48;
		}
		int j = System.in.read();
		while (j > 47) {i*=10;i+=j-48;j = System.in.read();}
		return (negative) ? -i : i;
}

public static String nextLine() throws Throwable {
		StringBuilder b = new StringBuilder(500);
		int j = System.in.read();
		while (j < 32) j = System.in.read();
		while (j != 10) {
			b=b.append((char)j);
			j=System.in.read();
		}
		//System.err.println("Input : " + b);
		return b.toString();
	}}