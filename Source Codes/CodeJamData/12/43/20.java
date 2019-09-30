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
		A:
		for (int t = 0; t < tt; t++) {
			int n = nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n-1; i++) {
				arr[i] = nextInt()-1;
			}
			int[] leng = new int[n];
			for (int it = 0; it < 1000; it++) {
				for (int i = 0; i < n-1; i++) {
					int minLeng = 0;
					for (int j = i+1; j < n; j++) {
						if (j != arr[i]) {
							minLeng = Math.max(minLeng, leng[i] + (leng[j]-leng[i]) * (arr[i]-i) / (j-i) + 1);
						}
					}
					leng[arr[i]] = Math.max(leng[arr[i]], minLeng);
				}
				boolean f = true;
				for (int i = 0; i < n; i++) {
					for (int j = i+1; j < n; j++) {
						if (j != arr[i]) {
							if ((leng[j]-leng[i])*1.0 / (j-i) < (leng[arr[i]]-leng[i])*1.0 / (arr[i]-i)) {
								
							} else {
								f = false;
							}
						}
					}
				}
				if (f) {
					out.print("Case #" + (t+1) + ":");
					for (int i = 0; i < n; i++) {
						out.print(' ');
						out.print(leng[i]);
					}
					out.println();
					continue A;
				}
			}
			out.print("Case #" + (t+1) + ":");
			out.println(" Impossible");
		}
		out.flush();
	}
}
