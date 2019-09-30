import java.lang.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static BufferedReader br;
	public static PrintWriter out;
	public static StringTokenizer stk;

	// ///////////////// TO CHANGE ///////////////////////////
	public static boolean isServer = false;

	// ///////////////// TO CHANGE ///////////////////////////

	public static void main(String[] args) throws IOException {
		if (isServer) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter(new File("out.txt"));
		}

		(new Solution()).run();
	}

	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return "";
		}
	}

	public String nextWord() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return stk.nextToken();
	}

	public Integer nextInt() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Integer.valueOf(stk.nextToken());
	}

	public Long nextLong() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Long.valueOf(stk.nextToken());
	}

	public Double nextDouble() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Double.valueOf(stk.nextToken());
	}

	public Float nextFloat() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Float.valueOf(stk.nextToken());
	}
	
	public void run() {
		int tt = nextInt();
		for (int t = 0; t < tt; t++) {
			int n = nextInt();
			int k = nextInt();
			
			int[][] arrn = new int[n][n];
			for (int i = 0; i < n; i++) {
				String s = nextWord();
				for (int j = 0; j < n; j++) {
					if (s.charAt(j) == '.') arrn[i][j] = 0;
					if (s.charAt(j) == 'R') arrn[i][j] = 1;
					if (s.charAt(j) == 'B') arrn[i][j] = 2;
				}
			}
			
			int[][] arr = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[j][n-i-1] = arrn[i][j];
				}
			}
			
			// Gravity
			for (int i = n-1; i >= 0; i--) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] != 0) {
						int cur = i;
						while (cur+1 < n && arr[cur+1][j] == 0) {
							arr[cur+1][j] = arr[cur][j];
							arr[cur][j] = 0;
							cur++;
						}
					}
				}
			}
			
			// get hor
			boolean[] f = new boolean[3];
			for (int i = 0; i < n; i++) {
				int cnt = 1;
				int cur = arr[i][0];
				for (int j = 1; j < n; j++) {
					if (arr[i][j] == cur) {
						cnt++;
					} else {
						if (cnt >= k) f[cur] = true;
						cnt = 1;
						cur = arr[i][j];
					}
				}
				if (cnt >= k) f[cur] = true;
			}
			
			// get vert
			for (int i = 0; i < n; i++) {
				int cnt = 1;
				int cur = arr[0][i];
				for (int j = 1; j < n; j++) {
					if (arr[j][i] == cur) {
						cnt++;
					} else {
						if (cnt >= k) f[cur] = true;
						cnt = 1;
						cur = arr[j][i];
					}
				}
				if (cnt >= k) f[cur] = true;
			}
			
			for (int i = 0; i < n; i++) {
				int cx = i;
				int cy = 0;
				int cnt = 1;
				int cur = arr[cx][cy];
				int d = 1;
				while (d + cx < n && d + cy < n) {
					if (arr[d+cx][d+cy] == cur) {
						cnt++;
					} else {
						if (cnt >= k) f[cur] = true;
						cnt = 1;
						cur = arr[d+cx][d+cy];
					}
					d++;
				}
				if (cnt >= k) f[cur] = true;
			}
			
			for (int i = 0; i < n; i++) {
				int cx = 0;
				int cy = i;
				int cnt = 1;
				int cur = arr[cx][cy];
				int d = 1;
				while (d + cx < n && d + cy < n) {
					if (arr[d+cx][d+cy] == cur) {
						cnt++;
					} else {
						if (cnt >= k) f[cur] = true;
						cnt = 1;
						cur = arr[d+cx][d+cy];
					}
					d++;
				}
				if (cnt >= k) f[cur] = true;
			}
			
			for (int i = 0; i < n; i++) {
				int cx = i;
				int cy = 0;
				int cnt = 1;
				int cur = arr[cx][cy];
				int d = 1;
				while (-d + cx >= 0 && d + cy < n) {
					if (arr[-d+cx][d+cy] == cur) {
						cnt++;
					} else {
						if (cnt >= k) f[cur] = true;
						cnt = 1;
						cur = arr[-d+cx][d+cy];
					}
					d++;
				}
				if (cnt >= k) f[cur] = true;
			}
			
			for (int i = 0; i < n; i++) {
				int cx = n-1;
				int cy = i;
				int cnt = 1;
				int cur = arr[cx][cy];
				int d = 1;
				while (-d + cx >= 0 && d + cy < n) {
					if (arr[-d+cx][d+cy] == cur) {
						cnt++;
					} else {
						if (cnt >= k) f[cur] = true;
						cnt = 1;
						cur = arr[-d+cx][d+cy];
					}
					d++;
				}
				if (cnt >= k) f[cur] = true;
			}
			
			String ans = "Neither";
			if (f[1] && f[2]) ans = "Both";
			if (f[1] && !f[2]) ans = "Red";
			if (!f[1] && f[2]) ans = "Blue";
			out.printf("Case #%d: %s\n", t+1, ans);
		}
		out.flush();
	}
}
