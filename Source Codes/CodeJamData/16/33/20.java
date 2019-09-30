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

public class C_sma {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	static int []j,p,s;
	static int[][]cnt1, cnt2, cnt3;
	static int t, K, ans_mask;
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
//		br = new BufferedReader(new FileReader("C-small.in"));
//		pw = new PrintWriter(new BufferedWriter(new FileWriter("C-small.out")));
		int cnttest = nextInt();
		for (int test = 1; test <= cnttest; test++) {
			pw.print("Case #"+test+": ");
			int J = nextInt();
			int P = nextInt();
			int S = nextInt();
			K = nextInt();
			j = new int[50];
			p = new int[50];
			s = new int[50];
			t = 0;
			for (int i1 = 1; i1 <= J; i1++) {
				for (int i2 = 1; i2 <= P; i2++) {
					for (int i3 = 1; i3 <= S; i3++) {
						j[t] = i1;
						p[t] = i2;
						s[t] = i3;
						t++;
					}
				}
			}
			cnt1 = new int[11][11];
			cnt2 = new int[11][11];
			cnt3 = new int[11][11];
			ans_mask = 0;
			go(0, 0);
			pw.println(Integer.bitCount(ans_mask));
			for (int i = 0; i < t; i++) {
				if ((ans_mask & (1 << i)) != 0) {
					pw.println(j[i]+" "+p[i]+" "+s[i]);
				}
			}
		}
		pw.close();
	}


	private static void go(int i, int mask) {
		if (i==t) {
			if (Integer.bitCount(mask) > Integer.bitCount(ans_mask))
				ans_mask = mask;
			return;
		}
		if (cnt1[j[i]][p[i]] < K && cnt2[j[i]][s[i]] < K && cnt3[p[i]][s[i]] < K) {
			cnt1[j[i]][p[i]]++;
			cnt2[j[i]][s[i]]++;
			cnt3[p[i]][s[i]]++;
			go(i+1, mask | (1 << i));
			cnt1[j[i]][p[i]]--;
			cnt2[j[i]][s[i]]--;
			cnt3[p[i]][s[i]]--;
		}
		go(i+1, mask);
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
