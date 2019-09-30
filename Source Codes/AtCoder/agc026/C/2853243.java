import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String s = in.next();
		char[] l = new char[n];
		char[] r = new char[n];
		for(int i=0;i<n;i++) {
			l[i] = s.charAt(i);
			r[i] = s.charAt(2*n-1-i);
		}
		char[][] buf = new char[2][n];
		long count = 0;
		for(int i=0;i<(1<<n);i++) {
			int[] p = new int[2];
			for(int j=0;j<n;j++) {
				int k = (i>>j)&1;
				buf[k][p[k]++] = l[j];
			}
			long[][] dp = new long[p[0] + 1][p[1] + 1];
		    dp[0][0] = 1;
		    for (int x = 0; x <= p[0]; x ++) {
		      for (int y = 0; y <= p[1]; y ++) {
		        if (x < p[0] && r[x + y] == buf[0][x]) {
		          dp[x + 1][y] += dp[x][y];
		        }
		        if (y < p[1] && r[x + y] == buf[1][y]) {
		          dp[x][y + 1] += dp[x][y];
		        }
		      }
		    }
		    count += dp[p[0]][p[1]];
		}
		System.out.println(count);
		in.close();
	}

}