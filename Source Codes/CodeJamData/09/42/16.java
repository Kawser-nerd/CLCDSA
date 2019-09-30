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


public class B {
	

	Object solve() {
		int R = sc.nextInt();
		int C = sc.nextInt();
		int F = sc.nextInt();
		sc.nextLine();
		
		int[] bm = new int[R+1];
		char[][] m = new char[R][];
		for (int i = 0; i < R; i++) {
			m[i] = sc.nextLine().toCharArray();
			for (int j = 0; j < C; j++) {
				if (m[i][j] == '.') {
					bm[i] |= (1<<j);
				}
			}
		}
		
		boolean[][][][] vis = new boolean[R][C][1<<C][1<<C];
		PriorityQueue<State> pq = new PriorityQueue<State>();
		pq.add(new State(0, 0, 0, bm[0], bm[1]));
		while (!pq.isEmpty()) {
			State s = pq.poll();
			int x = s.r;
			int y = s.c;
			int bm1 = s.bm1;
			int bm2 = s.bm2;
//			System.out.println(x + " " + y + " " + s.n);
			
			if (x == R - 1) return "Yes " +  s.n;
			
			if (vis[x][y][bm1][bm2]) continue;
			vis[x][y][bm1][bm2] = true;

			
			for (int dy = -1; dy <= 1; dy += 2) {
				int y1 = y + dy;
				if (valid (x, y1, R, C)) {
					if (free(bm1, y1)) {
						
						if (free(bm2, y1)) {
							int x1 = x+1;
							while (x1+1 < R && free(bm[x1+1], y1)) {
								x1++;
							}
							if (x1 - x > F) continue;
							int bm1a;
							if (x1 == x+1) {
								bm1a = bm2;
							} else {
								bm1a = bm[x1];
							}
							
							pq.add(new State(x1, y1, s.n, bm1a, bm[x1+1]));
						} else {
							pq.add(new State(x, y1, s.n, bm1, bm2));
							pq.add(new State(x, y, s.n+1, bm1, dig(bm2, y1)));
						}
					}
				}
			}
		}
		
		return "No";
	}
	
	int dig(int bm, int n) {
		return bm|(1<<n);
	}
	
	boolean free(int bm, int n) {
		return ((bm>>n)&1) == 1;
	}
	
	private boolean valid(int x, int y1, int r, int c) {
		return x >= 0 && x < r && y1 >= 0 && y1 < c;
	}

	static class State implements Comparable<State> {
		int r, c;
		int n;
		int bm1, bm2;
		
		public State(int r, int c, int n, int bm1, int bm2) {
			super();
			this.r = r;
			this.c = c;
			this.n = n;
			this.bm1 = bm1;
			this.bm2 = bm2;
		}

		@Override
		public int compareTo(State o) {
			return n - o.n;
		}
	}
	

	int[] ia(String s) { String[] a = s.split("\\s+"); int[] r = new int[a.length]; for (int i = 0; i < r.length; i++) r[i] = parseInt(a[i]); return r; }
	
	
	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "B-small-attempt1.in";
//		inFile = "B-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new B().solve();
			fw.println(res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
