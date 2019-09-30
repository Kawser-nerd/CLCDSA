import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	static Semaphore processorSemaphore = new Semaphore(Runtime.getRuntime().availableProcessors());
	static Semaphore inputSemaphore = new Semaphore(1);
	static Semaphore outputSemaphore = new Semaphore(0);
	static String[] output;
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		output = new String[MAX_CASES];
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			processorSemaphore.acquire();
			inputSemaphore.acquire();
			new WorkThread(casenum).start();
		}
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			outputSemaphore.acquire();
		}
		for(String out: output) {
			pw.println(out);
		}
		pw.close();
	}

	static class WorkThread extends Thread {
		public int casenum;

		public WorkThread(int casenum) {
			super();
			this.casenum = casenum;
		}

		static final int UP = 0;
		static final int RIGHT = 1;
		static final int DOWN = 2;
		static final int LEFT = 3;

		public void run() {


			int r = readInt();
			int c = readInt();

			int[] order = new int[2*(r+c)];
			int[] otp = new int[2*(r+c)+1];
			for(int i = 0; i < order.length; i++) {
				order[i] = readInt();
				if(i%2 == 1) {
					otp[order[i]] = order[i-1];
					otp[order[i-1]] = order[i];
				}
			}



			/*
			 * PUT ALL INPUT CODE BEFORE THIS COMMENT
			 */
			inputSemaphore.release();

			char[][] ret = null;



			outer: for(int mask = 0; ret == null && mask < (1 << (r*c)); mask++) {
				char[][] grid = new char[r][c];
				int tempIndex = 0;

				Map<Vertex, Vertex> p = new HashMap<Vertex, Vertex>();
				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) {
						for(int k = 0; k < 4; k++) {
							p.put(new Vertex(i, j, k), new Vertex(i, j, k));
						}
					}
				}

				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) {
						if(j+1 < c) {
							merge(p, new Vertex(i, j, RIGHT), new Vertex(i, j+1, LEFT));
						}
						if(i+1 < r) {
							merge(p, new Vertex(i, j, DOWN), new Vertex(i+1, j, UP));
						}
					}
				}

				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) {
						if((mask&(1<<tempIndex++)) == 0) {
							grid[i][j] = '/';
							merge(p, new Vertex(i, j, UP), new Vertex(i, j, LEFT));
							merge(p, new Vertex(i, j, DOWN), new Vertex(i, j, RIGHT));
						}
						else {
							grid[i][j] = '\\';
							merge(p, new Vertex(i, j, UP), new Vertex(i, j, RIGHT));
							merge(p, new Vertex(i, j, DOWN), new Vertex(i, j, LEFT));
						}
					}
				}
				Vertex[] go = new Vertex[2*(r+c)+1];
				for(int i = 1; i <= c; i++) {
					go[i] = new Vertex(0, i-1, UP);
				}
				for(int i = c+1; i <= c+r; i++) {
					go[i] = new Vertex(i-(c+1), c-1, RIGHT);
				}
				for(int i = c+r+1; i <= c+r+c; i++) {
					go[i] = new Vertex(r-1, c-1 - (i - (c+r+1)), DOWN);
				}
				for(int i = c+r+c+1; i <= c+r+c+r; i++) {
					go[i] = new Vertex(r-1 - (i-(c+r+c+1)), 0, LEFT);
				}
				Map<Vertex, Integer> rev = new HashMap<Vertex, Integer>();
				for(int i = 1; i < go.length; i++) {
					rev.put(go[i], i);
				}
				Map<Vertex, ArrayList<Vertex>> last = new HashMap<Vertex, ArrayList<Vertex>>();
				int matches = 0;
				for(int i = 1; i < go.length; i++) {
					Vertex actual = find(p, go[i]);
					if(!last.containsKey(actual)) {
						last.put(actual, new ArrayList<Vertex>());
						last.get(actual).add(go[i]);
					}
					else if(last.get(actual).size() != 1) {
						continue outer;
					}
					else {
						int expect = otp[i];
						if(!go[expect].equals(last.get(actual).get(0))) {
							continue outer;
						}
						matches++;
					}
				}
				if(matches != r+c) {
					continue outer;
				}
				ret = grid;
			}


			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + casenum + ":\n");
			if(ret == null) {
				sb.append("IMPOSSIBLE\n");
			}
			else {
				for(int i = 0; i < r; i++) {
					sb.append(new String(ret[i]));
					sb.append("\n");
				}
			}

			sb.deleteCharAt(sb.length()-1);
			output[casenum-1] = sb.toString();

			/*
			 * PUT ALL WORK CODE BEFORE THIS COMMENT
			 * REMEMBER TO WRITE to output[casenum-1] the exact output
			 */



			outputSemaphore.release();
			processorSemaphore.release();
		}

		public void merge(Map<Vertex, Vertex> p, Vertex a, Vertex b) {
			Vertex fa = find(p, a);
			Vertex fb = find(p, b);
			p.put(fa, fb);
		}

		public Vertex find(Map<Vertex, Vertex> p, Vertex v) { 
			if(p.get(v).equals(v)) return v;
			Vertex actual = find(p, p.get(v));
			p.put(v, actual);
			return actual;
		}


		static class Vertex {
			public int r, c, orientation;

			public Vertex(int r, int c, int orientation) {
				super();
				this.r = r;
				this.c = c;
				this.orientation = orientation;
			}

			public String toString() {
				String ret = r + " " + c + " ";
				if(orientation == UP) ret += "UP";
				if(orientation == DOWN) ret += "DOWN";
				if(orientation == LEFT) ret += "LEFT";
				if(orientation == RIGHT) ret += "RIGHT";
				return ret;
			}

			@Override
			public int hashCode() {
				final int prime = 31;
				int result = 1;
				result = prime * result + c;
				result = prime * result + orientation;
				result = prime * result + r;
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
				Vertex other = (Vertex) obj;
				if (c != other.c)
					return false;
				if (orientation != other.orientation)
					return false;
				if (r != other.r)
					return false;
				return true;
			}

		}

	}

	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine());
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
