import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
	static long ans=1;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		HashMap<Integer,Integer> yakusu=new HashMap<Integer,Integer>();
		List <Integer> unko=new ArrayList<Integer>();
		int A=sc.nextInt();
		int B=sc.nextInt();
		long MOD=1_000_000_007L;
		if(A==B) {
			pl(1);
		}
		else {
			for(int i=B+1; i<=A; i++) {
				unko=new ArrayList<Integer>();
				fra(i,unko);
				for(int j=0; j<unko.size(); j++) {
					int a=unko.get(j);
					if(a>1) {
						if(yakusu.containsKey(a)) {
							yakusu.put(a, yakusu.get(a)+1);
						}
						else {
							yakusu.put(a, 1);
						}
					}
				}
			}
			yakusu.forEach((key,value)->{
				ans*=((long)(value+1));
				ans%=MOD;
				//pl(key+" "+value);
			});
			pl(ans);
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
	public static void fra(int a,List<Integer> p) {//int??
		for(int i=2; i*i<=a; i++) {
			if(a%i==0) {
				p.add(i);
				fra(a/i,p);
				return;
			}
		}
		if(a>1) {
			p.add(a);
		}
	}
}