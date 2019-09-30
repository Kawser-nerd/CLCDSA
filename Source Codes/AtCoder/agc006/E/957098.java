import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean solve() throws IOException {
		int n = nextInt();
		int[][] a = new int[3][n];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = nextInt() - 1;
			}
		}
		
		int[] perm = new int[n];
		boolean[] flip = new boolean[n];
		
		for (int i = 0; i < n; i++) {
			int cand = Math.min(a[0][i], Math.min(a[1][i], a[2][i]));
			if (cand % 3 != 0) {
				return false;
			}
			
			int what = cand / 3;
			if (a[0][i] == cand && a[1][i] == cand + 1 && a[2][i] == cand + 2) {
				perm[i] = what;
				flip[i] = false;
				continue;
			}
			
			if (a[2][i] == cand && a[1][i] == cand + 1 && a[0][i] == cand + 2) {
				perm[i] = what;
				flip[i] = true;
				continue;
			}
			
			return false;
		}
		
//		System.err.println(Arrays.toString(perm));
//		System.err.println(Arrays.toString(flip));
		
		int[] evenP = new int[(n + 1) / 2];
		
		int evenFlip = 0;
		for (int i = 0; i < n; i += 2) {
			if (flip[i]) {
				evenFlip++;
			}
			if (perm[i] % 2 == 1) {
				return false;
			}
			evenP[i / 2] = perm[i] / 2;
		}
		
		
		int[] oddP = new int[n / 2];
		int oddFlip = 0;
		for (int i = 1; i < n; i+= 2) {
			if (flip[i]) {
				oddFlip++;
			}
			if (perm[i] % 2 == 0) {
				return false;
			}
			oddP[i / 2] = perm[i] / 2;
		}
		
//		System.err.println(Arrays.toString(evenP) + " " + Arrays.toString(oddP));
		
		return (permParity(evenP) == oddFlip % 2) && (permParity(oddP) == evenFlip % 2); 
	}
	
	int permParity(int[] p) {
		int n = p.length;
		int ret = n & 1;
		
		boolean[] vis = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (vis[i]) {
				continue;
			}
			ret ^= 1;
			for (int j = i; !vis[j]; j = p[j]) {
				vis[j] = true;
			}
		}
		
		return ret;
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		out.println(solve() ? "Yes" : "No");
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}