import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main{
	static int max;
	static int[][] mjs;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		String s=sc.next();
		int[] alp=new int[26];
		Arrays.fill(alp, 0);
		for(int i=0; i<s.length(); i++) {
			alp[s.charAt(i)-97]++;
		}
		mjs=new int[s.length()][s.length()];
		for(int i=0; i<s.length(); i++) {
			Arrays.fill(mjs[i],-1);
		}
		for(int i=0; i<s.length(); i++) {
			mjs[0][i]=s.charAt(i)-97;
		}
		int answ=114514;
		for(max=0; max<26; max++) {
			for(int i=1; i<s.length(); i++) {
				for(int j=0; j<s.length()-i; j++) {
					if(mjs[i-1][j]!=max && mjs[i-1][j+1]!=max) {
						if(mjs[i-1][j+1]==-1) {
							mjs[i][j]=mjs[i-1][j];
						}
						else {
							mjs[i][j]=mjs[i-1][j];
						}
					}
					if(mjs[i-1][j]==max || mjs[i-1][j+1]==max) {
						mjs[i][j]=max;
					}
				}
			}
			for(int i=0; i<s.length(); i++) {
				boolean ans=ac(i);
				if(ans) {
					answ=Math.min(i, answ);
				}
			}
		}
		pl(answ);

		/*for(int i=0; i<s.length(); i++) {
			for(int j=0; j<s.length(); j++) {
				p(mjs[i][j]+" ");
			}
			pl();
		}*/
	}
	public static boolean ac(int a) {
		for(int i=0; i<mjs[0].length; i++) {
			if(mjs[a][i]!=-1 && max!=mjs[a][i]) {
				return false;
			}
			else if(mjs[a][i]==-1) {
				break;
			}
		}
		return true;
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
}