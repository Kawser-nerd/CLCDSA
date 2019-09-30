import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		String s=sc.next();
		long[] alp=new long[26];
		Arrays.fill(alp, 0);
		long len=(long)s.length();
		for(int i=0; i<len; i++) {
			alp[s.charAt(i)-97]++;
		}
		long[][] matrix=new long[26][26];
		for(int i=0; i<26; i++) {
			for(int j=0; j<26; j++) {
				if(i==j) {
					matrix[i][j]=0;
				}
				else {
					matrix[i][j]=alp[i]*alp[j];
				}
			}
		}
		long sum=0;
		for(int i=0; i<26; i++) {
			for(int j=0; j<26; j++) {
				if(i<j) {
					sum+=matrix[i][j];
				}
			}
		}
		pl(sum+1);
		//pl();
		for(int i=0; i<26; i++) {
			for(int j=0; j<26; j++) {
				if(i<j) {
					//p(matrix[i][j]+" ");
				}
			}
			//pl();
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