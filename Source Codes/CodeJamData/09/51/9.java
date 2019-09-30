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


public class A {
	

	Object solve() {
		R = sc.nextInt();
		C = sc.nextInt();
		String[] m1 = new String[R];
		for (int i = 0; i < R; i++)
			m1[i] = sc.next();
		
		char[][] m = addSentinels(m1, '#');
		num = new int[R+2][C+2];
		r = new int[(R+2)*(C+2)];
		c = new int[(R+2)*(C+2)];
		int cnt = 0;
		int B = 0;
		for (int i = 0; i < R+2; i++)
			for (int j = 0; j < C+2; j++) {
				r[cnt] = i;
				c[cnt] = j;
				num[i][j] = cnt++;
				if (m[i][j] == 'o' || m[i][j] == 'w')
					B++;
			}

		int[] start = new int[B];
		int[] target = new int[B];
		int starti = 0, targeti = 0;
		for (int i = 0; i < R+2; i++)
			for (int j = 0; j < C+2; j++) {
				if (m[i][j] == 'o' || m[i][j] == 'w')
					start[starti++] = num[i][j];
				if (m[i][j] == 'x' || m[i][j] == 'w')
					target[targeti++] = num[i][j];
			}
		
		State targetState = new State(target, 0);
		
//		System.out.println(Arrays.toString(target));
		
		HashSet<State> vis = new HashSet<State>();
		PriorityQueue<State> pq = new PriorityQueue<State>();
		
		pq.add(new State(start, 0));
		
		while (!pq.isEmpty()) {
			State st = pq.poll();
			int[] pos = st.pos;
			
			if (vis.contains(st)) continue;
			vis.add(st);
			
			if (st.equals(targetState)) return st.n;
			
			for (int i = 0; i < B; i++) {
				int x = r[pos[i]];
				int y = c[pos[i]];

				for (int d = 0; d < 2; d++) {
					int x1 = x + dx[d], x2 = x + dx[d+2];
					int y1 = y + dy[d], y2 = y + dy[d+2];
					
					if (free(m, pos, x1, y1) && free(m, pos, x2, y2)) {
						int[] pos1 = pos.clone();
						pos1[i] = num[x1][y1];
						State s1 = new State(pos1, st.n + 1);
						
						if (!st.dangerous || !s1.dangerous) {
							pq.add(s1);
						}
						
						int[] pos2 = pos.clone();
						pos2[i] = num[x2][y2];
						State s2 = new State(pos2, st.n + 1);
						
						if (!st.dangerous || !s2.dangerous) {
							pq.add(s2);
						}
					}
				}
			}
		}
		
		return -1;
	}
	
	private boolean free(char[][] m, int[] pos, int x1, int y1) {
		if (m[x1][y1] == '#') return false;
		int n = num[x1][y1];
		for (int i = 0; i < pos.length; i++)
			if (pos[i] == n) return false;
		return true;
	}

	static final int[] dx = new int[] {-1, 0, 1, 0}, dy = new int[] {0, 1, 0, -1};
	
	class State implements Comparable<State> {
		int[] pos;
		boolean dangerous;
		int n;
		

		public State(int[] pos, int n) {
			sort(pos);
			this.pos = pos;
			dangerous = isDangerous();
			this.n = n;
			String s = "";
			for (int i = 0; i < pos.length; i++)
				s += r[pos[i]] + "|" + c[pos[i]] + ", ";
			
//			System.out.println(s + " " + dangerous + " " + n);
		}
		
		boolean isDangerous() {
			DisjointSets ds = new DisjointSets(pos.length);
			for (int i = 0; i < pos.length; i++)
				for (int j = i+1; j < pos.length; j++) {
					if (pos[j] - pos[i] == C+2 || pos[j] - pos[i] == 1)
						ds.union(i, j);
				}
			return ds.setCount > 1;
		}

		int hash;
		@Override
		public int hashCode() {
			if (hash != 0) return hash; 
			return hash = Arrays.hashCode(pos);
		}

		@Override
		public boolean equals(Object obj) {
			State other = (State) obj;
			if (!Arrays.equals(pos, other.pos))
				return false;
			return true;
		}

		@Override
		public int compareTo(State o) {
			return this.n - o.n;
		}
	}
	
	static class DisjointSets {
		int setCount;
		int[] parent;

		public DisjointSets(int count) {
			setCount = count;
			parent = new int[count];
			Arrays.fill(parent, -1);
		}

		public int findSet(int elem) {
			return parent[elem] == -1 ? elem : (parent[elem] = findSet(parent[elem]));
		}
		
		public boolean union(int elem1, int elem2) {
			int root1 = findSet(elem1), root2 = findSet(elem2);
			if (root1 == root2) return false;

			if (Math.random() < 0.5) 
				parent[root1] = root2;
			else
				parent[root2] = root1;

			--setCount;
			return true;
		}
	}
	
	
	private static char[][] addSentinels(String[] s, char c) {
		char[][] res = new char[s.length+2][s[0].length()+2];
		Arrays.fill(res[0], c);
		Arrays.fill(res[res.length-1], c);
		for (int i = 0; i < s.length; i++) 
			res[i + 1] = (c + s[i] + c).toCharArray();
		return res;
	}


	int[] ia(String s) { String[] a = s.split("\\s+"); int[] r = new int[a.length]; for (int i = 0; i < r.length; i++) r[i] = parseInt(a[i]); return r; }
	
	private static Scanner sc; private static PrintWriter fw;

	private int[] r;

	private int[] c;

	private int[][] num;

	private int R;

	private int C;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "A-small-attempt0.in";
		inFile = "A-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
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
