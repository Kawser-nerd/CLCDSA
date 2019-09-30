import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.fill;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

//	String inputFile = "sample.txt";
//	String inputFile = "input/B-small-attempt2.in";
	String inputFile = "input/B-large.in";
	
	String outputFile = "output.txt";
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
	
		for (int testCase = 1, testCount = nextInt(); testCase <= testCount; testCase++) {
			solve(testCase);
		}
		
		out.close();
	}

	/* Solving */
	int MAXN = 1000000;
	
	int N;
	int L;
	long t;
	int C;
	int[] a;
	
	List<Item> items = new ArrayList<Main.Item>(MAXN);
	int[] lens = new int [MAXN];
	
	boolean[] build = new boolean [MAXN];
	
	void solve(int testCase) throws IOException {
		System.out.println(testCase);
		
		/* Input */
		L = nextInt();
		t = nextLong();
		N = nextInt();
		C = nextInt();
		a = new int [C];
		for (int i = 0; i < C; i++)
			a[i] = nextInt();
		
		items.clear();
		for (int i = 0; i < C; i++) {
			for (int k = 0; k * C + i < N; k++) {
				int ind = k * C + i;
				lens[ind] = a[i];
				items.add(new Item(ind, a[i]));
			}
		}
//		System.out.println(Arrays.toString(Arrays.copyOf(lens, N)));
		
		/* Solution */
		fill(build, 0, N, false);
		Collections.sort(items);
		int pnt = 0;
		for (; pnt < L; pnt++)
			build[items.get(pnt).id] = true;
		
		long time = 0L;
		for (int i = 0; i < N; i++) {
			while (pnt < N && items.get(pnt).id <= i)
				pnt++;
			if (build[i]) {
				if (time >= t) {
					time += lens[i];
				} else {
					long curEnd = time + 2L * lens[i];
					long curTimeNeed = t - time;
					if (curEnd <= t) {
						build[i] = false;
						if (pnt < N) {
							build[items.get(pnt).id] = true;
							pnt++;
						}
						time += 2L * lens[i];
					} else {
						if (pnt < N) {
							Item nxt = items.get(pnt);
							long curTimeSave = 2L * lens[i] - curTimeNeed;
							long nxtTimeSave = 2L * lens[nxt.id];
							if (nxtTimeSave > curTimeSave) {
								build[i] = false;
								build[nxt.id] = true;
								pnt++;
								
								time += 2L * lens[i];
							} else {
								if (curTimeNeed % 2 == 1)
									System.err.println("BAD");
								time += curTimeNeed + (lens[i] - curTimeNeed / 2L);
							}
						} else {
							if (curTimeNeed % 2 == 1)
								System.err.println("BAD");
							time += curTimeNeed + (lens[i] - curTimeNeed / 2L);
						}
					}
				}
			} else {
				time += 2L * lens[i];
			}
		}
		
		/* Output */
		out.print("Case #" + testCase + ": ");
		out.println(time);
		
	}
	
	class Item implements Comparable<Item> {
		int id;
		long len;
		
		Item(int id, long len) {
			this.id = id;
			this.len = len;
		}

		@Override
		public int compareTo(Item item) {
			if (len != item.len) return len > item.len ? -1 : 1;
			return item.id - id;
		}
	}
	
	/*************************************************************** 
	 * Input 
	 **************************************************************/
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
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
	
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
