import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class A {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	static class Sort implements Comparable<Sort> {
		int val, ind;
		public int compareTo(Sort arg0) {
			return -(this.val-arg0.val);
		}
		public Sort(int val, int ind) {
			this.val = val;
			this.ind = ind;
		}
	}
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
//		br = new BufferedReader(new FileReader("A-small.in"));
//		pw = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
		int cnttest = nextInt();
		for (int test = 1; test <= cnttest; test++) {
			pw.print("Case #"+test+": ");
			int n = nextInt();
			int[]p = new int[n+1];
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				p[i] = nextInt();
				sum += p[i];
			}
			PriorityQueue<Sort> q = new PriorityQueue<>();
			for (int i = 1; i <= n; i++) {
				q.add(new Sort(p[i], i));
			}
			while (!q.isEmpty()) {
				if (q.size()==1) {
					int ind = q.poll().ind;
					pw.print((char)(ind+'A'-1)+" ");
					p[ind]--;
					sum--;
					if (p[ind] > 0)
						q.add(new Sort(p[ind], ind));
				}
				else {
					int i = q.poll().ind;
					int j = q.poll().ind;
					if (2*p[j] > sum-1) {
						pw.print((char)(i+'A'-1)+""+(char)(j+'A'-1)+" ");
						p[i]--;
						p[j]--;
						sum -= 2;
						if (p[i] > 0)
							q.add(new Sort(p[i], i));
						if (p[j] > 0)
							q.add(new Sort(p[j], j));
					}
					else {
						pw.print((char)(i+'A'-1)+" ");
						p[i]--;
						sum--;
						if (p[i] > 0)
							q.add(new Sort(p[i], i));
						q.add(new Sort(p[j], j));
					}
				}
			}
			pw.println();
		}
		pw.close();
	}


	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
