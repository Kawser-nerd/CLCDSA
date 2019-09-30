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
	
	int W, Q;
	char[][] f;

	Object solve() {
		W = sc.nextInt();
		Q = sc.nextInt();
		sc.nextLine();
		f = new char[W][W];
		for (int i = 0; i < W; i++)
			f[i] = sc.nextLine().toCharArray();
	
		boolean[][][] vis = new boolean[W][W][5000];
		PriorityQueue<State> pq = new PriorityQueue<State>();
		for (int k = 0; k < W; k++) {
			for (int l = 0; l < W; l++) {
				if (!isDigit(f[k][l])) continue;
				pq.add(new State(k, l, f[k][l] - '0', 1, f[k][l], '\0', null));
			}
		}
		
		int[] q = new int[Q];
		for (int h = 0; h < Q; h++) {
			q[h] = sc.nextInt();
		}
		
		State[] best = new State[Q];
		int rem = Q;		
		
		while (rem > 0) {
			State st = pq.poll();
			
			int n = st.value;
			int x = st.x;
			int y = st.y;

			for (int h = 0; h < Q; h++) {
				if (n == q[h] && best[h] == null) {
					best[h] = st;
					rem--;
				}
			}
			
			if (n < -2000 || n > 2000)
				continue;
			
			if (vis[x][y][n+2500]) 
				continue;
			vis[x][y][n+2500] = true;
			
			for (int i = 0; i < 4; i++) {
				int x1 = x + dx[i], y1 = y + dy[i];
				if (!valid(x1, y1)) continue;
				for (int j = 0; j < 4; j++) {
					int x2 = x1 + dx[j], y2 = y1 + dy[j];
					if (!valid(x2, y2)) continue;
					int m = f[x2][y2] - '0';
					int res;
					switch (f[x1][y1]) {
					case '+': res = n + m; break;
					case '-': res = m + n - (2*(st.num - '0')); break;
					default: throw new AssertionError();
					}
					State s1 = new State(x2, y2, res, st.len + 1, f[x2][y2], f[x1][y1], st);
					pq.add(s1);
				}
			}
		}
		
		for (int i = 0; i < Q; i++)
			fw.println(best[i]);
		
		return null;
	}
	
	static class State implements Comparable<State> {
		int x, y;
		int value;
		int len;
		char num;
		char sign;
		State next;
		
		public State(int x, int y, int value, int len, char num, char sign, State next) {
			this.x = x;
			this.y = y;
			this.value = value;
			this.len = len;
			this.next = next;
			this.sign = sign;
			this.num = num;
		}

		@Override
		public int compareTo(State o) {
			if (len < o.len)
				return -1;
			if (len > o.len)
				return 1;
			
			if (next == null)
				return 0;
			
			if (num != o.num)
				return num - o.num;
			
			if (sign != o.sign)
				return sign - o.sign;
			
			return next.compareTo(o.next);
		}
		
		public String toString() {
			String s = "" + num;
			if (next != null) {
				s += sign;
				s += next.toString();
			}
			return s;
		}
	}
	
	private boolean valid(int x, int y) {
		return x >= 0 && y >= 0 && x < W && y < W;
	}

	static final int[] dx = new int[] {-1, 1, 0, 0}, dy = new int[] {0, 0, -1, 1};

	int[] ia(String s) { String[] a = s.split("\\s+"); int[] r = new int[a.length]; for (int i = 0; i < r.length; i++) r[i] = parseInt(a[i]); return r; }
	
	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "C-small-attempt3.in";
		inFile = "C-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
//			fw.print("Case #" + cas + ": ");
			fw.println("Case #" + cas + ": ");
			Object res = new C().solve();
//			fw.println(res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
