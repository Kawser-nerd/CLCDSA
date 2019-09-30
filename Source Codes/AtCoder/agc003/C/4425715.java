import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		HashMap<Integer,Integer> unko=new HashMap<Integer,Integer>();
		int[] buri=new int[N];
		int[] cpy=new int[N];
		for(int i=0; i<N; i++) {
			buri[i]=sc.nextInt();
			cpy[i]=buri[i];
		}
		Arrays.sort(buri);
		for(int i=0; i<N; i++) {
			unko.put(buri[i],i);
		}
		int[] moto=new int[N];
		for(int i=0; i<N; i++) {
			moto[i]=unko.get(cpy[i]);
			//pl(moto[i]);
		}
		int kigu=0;
		for(int i=0;i<N; i++) {
			if(i%2!=moto[i]%2) {
				kigu++;
			}
		}
		pl(kigu/2);
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