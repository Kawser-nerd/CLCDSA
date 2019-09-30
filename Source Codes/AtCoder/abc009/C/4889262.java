import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		final int N = sc.nextInt();	//???????
		final int K = sc.nextInt();	//??????????????
		final String s = sc.next();	//???
		int[] cNum = new int[26];	//?????????
		for(int i=0; i<26; i++) {
			cNum[i]=0;
		}
		for(int i=0; i<N; i++) {
			cNum[s.charAt(i)-'a']++;
		}
		String ans = "";	//??
		int count = K;
		for(int i=0; i<N; i++){
			char currentC = s.charAt(i);	//?????
			boolean replace = false;
			for(int j=0; j<cNum.length; j++){
				cNum[j]--;
				if( cNum[j]>=0 && ( currentC == j+'a' || canReplace(s.substring(i+1, N), cNum, count-1))){
					if(currentC != j+'a') count--;
					ans +=(char)(j+'a');
					replace = true;
					break;
				}else{
					cNum[j]++;
				}
			}
			if(!replace){
				ans += currentC;
				cNum[currentC-'a']--;
			}
		}
		pl(ans);
	}

	private static boolean canReplace(String substring, int[] cNum, int count) {
		int[] tmpNum = new int[26];
		for(int i=0; i<26; i++) tmpNum[i] = cNum[i];
		int replaceCount = 0;
		for(char c: substring.toCharArray()){
			if(tmpNum[c-'a']>0){
				tmpNum[c-'a']--;
			}else{
				replaceCount++;
			}
		}
		return count >= replaceCount;
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