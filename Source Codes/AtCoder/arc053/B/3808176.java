import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		String s=sc.next();
		int[] alpha=new int[26];
		for(int i=0; i<26; i++) {
			alpha[i]=0;
		}
		for(int i=0; i<s.length(); i++) {
			alpha[(s.charAt(i))-97]++;
		}
		int kisu=0;
		int use=0;
		for(int i=0; i<26; i++) {
			if(alpha[i]%2==1) {
				use+=alpha[i]-1;
				kisu++;
			}
			else {
				use+=alpha[i];
			}
		}
		if(kisu==0) {
			System.out.println((use));
		}
		else {
			System.out.println((1+2*(use/(kisu*2))));
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
	}
}