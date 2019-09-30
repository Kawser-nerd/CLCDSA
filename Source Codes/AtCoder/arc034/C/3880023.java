import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		long A=sc.nextLong();
		long B=sc.nextLong();
		if(A==B) {
			pl(1);
			System.exit(0);
		}
		List<Long> unko=new ArrayList<Long>();
		long[] yks=new long[5000];
		for(int i=0; i<5000; i++) {
			yks[i]=0;
		}
		int cnt=0;
		for(long i=B+1; i<=A; i++) {
			unko=new ArrayList<Long>();
			fra(i,unko);
			for(int j=0; j<unko.size(); j++) {
				long tm=unko.get(j);
				if(tm>1) {
					yks[cnt]=tm;
					cnt++;
				}
			}
		}
		long[] reform=new long[cnt];

		for(int i=0; i<cnt; i++) {
			reform[i]=yks[i];
		}
		Arrays.sort(reform);
		long now=reform[0];
		long kosu=1;
		long sum=1;
		int lsm=0;
		for(int i=1; i<cnt; i++) {
			if(reform[i]!=now) {
				sum*=(kosu+1);
				sum%=1000000007;
				now=reform[i];
				kosu=1;
				lsm=i;
			}
			else {
				kosu++;
			}
		}
		sum*=(kosu+1);
		sum%=1000000007;
		pl(sum);
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
	public static void p(Object o) {
		System.out.print(o);
	}
	public static void fra(int a,List<Integer> p) {//int??
		for(int i=2; i*i<=a; i++) {
			if(a%i==0) {
				p.add(i);
				fra(a/i,p);
				return;
			}
		}
		p.add(a);
	}

	public static void fra(long a,List<Long> p) {//long??
		for(long i=2; i*i<=a; i++) {
			if(a%i==0) {
				p.add(i);
				fra(a/i,p);
				return;
			}
		}
		p.add(a);
	}
}