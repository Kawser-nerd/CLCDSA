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
	
	static class State implements Comparable<State> {
		int n, m, t;

		public State(int n, int m, int t) {
			super();
			this.n = n;
			this.m = m;
			this.t = t;
		}
		

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + m;
			result = prime * result + n;
			return result;
		}




		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (m != other.m)
				return false;
			if (n != other.n)
				return false;
			return true;
		}




		@Override
		public int compareTo(State o) {
//			if (waited != o.waited) {
//				return waited ? 1 : -1;
//			}
			return t - o.t;
		}


	}
	
	int[] dx = new int[] {-1, 0, 1, 0}, dy = new int[] {0,1,0,-1};

	Object solve() {
		
		System.out.println(" ++");
		
		int H = sc.nextInt();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] c = new int[N][M];
		int[][] h = new int[N][M];
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) 
				c[i][j] = sc.nextInt();
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) 
				h[i][j] = sc.nextInt();
		
		PriorityQueue<State> pq = new PriorityQueue<B.State>();
		HashSet<State> vis = new HashSet<B.State>();
		pq.add(new State(0,0,0));
		
		while (!pq.isEmpty()) {
			State s = pq.poll();
			
//			System.out.println(s.n + " " + s.m + " " + s.t);
			
			if (s.n == N-1 && s.m == M-1) 
				return s.t/10 + "." + s.t%10;
			
			int n = s.n;
			int m = s.m;
			
			if (vis.contains(s)) continue;
			vis.add(s);
			
			for (int d = 0; d < 4; d++) {
				int n1 = s.n + dx[d];
				int m1 = s.m + dy[d];
				if (n1 < 0 || m1 < 0 || n1 >= N || m1 >= M) continue;
				
				int wnow = H - s.t; 
				if (h[n][m] <= c[n1][m1] - 50 && h[n1][m1] <= c[n1][m1] - 50 && h[n1][m1] <= c[n][m] - 50) {
//					if (wnow <= c[n1][m1] - 50) {
//						int wrem = wnow - h[n][m];
//						if (wrem >= 20) {
//							pq.add(new State(n1, m1, nt(s.t, 10)));
//						} else {
//							pq.add(new State(n1, m1, nt(s.t, 100)));
//						}
//					} else {
					int t1 = max(s.t, H - c[n1][m1] + 50);
					int wrem = H - t1 - h[n][m];
					if (wrem >= 20) {
						pq.add(new State(n1, m1, nt(t1, 10)));
					} else {
						pq.add(new State(n1, m1, nt(t1, 100)));
					}
//					}
				}
			}
		}
		
		return "0";
	}
	
	int nt(int time, int add) {
		if (time == 0) return 0;
		return time + add;
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "B-small-attempt0.in";
		inFile = "B-large.in";
		
		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new B().solve();
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
