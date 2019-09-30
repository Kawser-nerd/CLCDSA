import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {
	static int kaisu=0;
	static long score_max=Long.MAX_VALUE;
	static long score_min=0;
	static int N;
	static long[] balloon;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		N=sc.nextInt();
		balloon=new long[N*2];
		for(int i=0; i<N; i++) {
			balloon[i]=sc.nextLong();		//H_i
			balloon[i+N]=sc.nextLong();		//S_i
		}
		long mid=0;
		while(Math.abs(score_max-score_min)>1) {
			mid=(score_max+score_min)/2;
			if(solve(mid)) {
				score_max=mid;
			}
			else {
				score_min=mid;
			}
		}
		if(solve(score_min)) {
			pl(score_min);
		}
		else {
			pl(score_max);
		}
	}
	public static boolean solve(long mid) {
		long[] time=new long[N];
		for(int i=0; i<N; i++) {
			if(mid-balloon[i]<0) {
				return false;
			}
			time[i]=(mid-balloon[i])/balloon[i+N];
		}
		Arrays.sort(time);
		for(int i=0; i<N; i++) {
			if(time[i]<i) {
				return false;
				//
			}
		}
		return true;
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
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
}