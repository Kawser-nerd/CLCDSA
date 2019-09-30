import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

class sushi {
	public int t;
	public long d;

	public sushi(int t, long d) {
		this.t = t;
		this.d = d;
	}

	public long getD() {
		return this.d;	//???????
	}
}

public class Main {

	static SC sc=new SC(System.in);
	static Stack<Long> st = new Stack<Long>();
	static int N = sc.nextInt();
	static int K = sc.nextInt();
	static sushi[] S = new sushi[N];
	static boolean[] used = new boolean[N + 1];
	static long sum_t = 0;
	static long sum_d = 0;
	static long ans = 0;

	public static void main(String[] args) {
		for(int i = 0; i < N; i++) {
			int t = sc.nextInt();	//??
			long d = sc.nextLong();	//????
			sushi su = new sushi(t, d);  //sushi?
			S[i] = su;		//sushi??????
		}
		show();
		Arrays.sort(S, Comparator.comparing(sushi::getD).reversed());		//????????????
		for(int i = 0; i < K; i++) {
			if(used[S[i].t]) {		//???????????
				st.push(S[i].d);
			} else {
				used[S[i].t] = true;
				sum_t++;
			}
			sum_d += S[i].d;
		}
		ans = sum_d + sum_t * sum_t;

		for(int i = K; i < N; i++) {
			if(st.empty())
				break;
			if(used[S[i].t])
				continue;
			used[S[i].t] = true;	//??????????????????
			sum_t++;
			sum_d += S[i].d - (long) st.pop();
			ans = Math.max(ans, sum_d + sum_t * sum_t);
		}

		pl(ans);
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}
	}
	public static void show() {
		for(int i=0; i<=N; i++) {
			//pl(used[i]);
		}
	}
}