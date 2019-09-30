import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int N=sc.nextInt();
		PriorityQueue<Long> Q=new PriorityQueue<Long>();
		long sum=0;
		long[] ary=new long[3*N];
		long[][] awase=new long[N+1][2];
		for(int i=0; i<N*3; i++) {
			long tmp=sc.nextLong();
			ary[i]=tmp;
			if(i<N) {
				Q.offer(tmp);
				sum+=tmp;
				awase[0][0]=sum;
			}
			else if(i>=N && i<2*N){
				long a=Q.peek();
				if(a<tmp) {
					Q.poll();
					Q.offer(tmp);
					sum+=(tmp-a);
				}
				else {
					//
				}
				awase[i-(N-1)][0]=sum;
			}
		}
		Q=new PriorityQueue<Long>();
		sum=0;
		for(int i=3*N-1; i>=N; i--) {
			long tmp=-ary[i];
			if(i>=2*N) {
				Q.offer(-ary[i]);
				sum+=ary[i];
				awase[Math.min(i-N,N)][1]=sum;
				//pl(Q.size());
			}
			else {
				long a=Q.peek();
				if(a<tmp) {
					Q.poll();
					Q.offer(tmp);
					sum-=(tmp-a);
				}
				else {
					//
				}
				awase[Math.min(i-N,N)][1]=sum;
			}
		}
		long max=Long.MIN_VALUE;
		for(int i=0; i<=N; i++) {
			max=Math.max(awase[i][0]-awase[i][1], max);
		}
		pl(max);
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