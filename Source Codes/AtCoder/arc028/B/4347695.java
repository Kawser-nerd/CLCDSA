import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
public class Main {
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		PriorityQueue<Integer> PQ=new PriorityQueue<Integer>();
		int N=sc.nextInt();
		int K=sc.nextInt();
		int[] arx=new int[N+1];
		int[] ary=new int[N];
		for(int i=0; i<N; i++) {
			int tmp=sc.nextInt();
			ary[i]=tmp;
			arx[tmp]=i+1;
		}
		for(int i=0; i<N; i++) {
			int tmp=ary[i];
			if(i<K) {
				if(i==K-1) {
					PQ.offer(-tmp);
					pl(arx[-PQ.peek()]);
				}
				else {
					PQ.offer(-tmp);
				}
			}
			else {
				int biri=-PQ.peek();
				if(biri>tmp) {
					PQ.offer(-tmp);
					PQ.poll();
					pl(arx[-PQ.peek()]);
				}
				else {
					pl(arx[-PQ.peek()]);
				}
			}
		}
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