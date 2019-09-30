import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		String[] bu=s.split(" ");
		StringBuilder sb=new StringBuilder();
		for(int i=0; i<bu.length-1; i++) {
			if(bu[i].charAt(0)=='L') {
				sb.append("< ");
			}
			else if(bu[i].charAt(0)=='R') {
				sb.append("> ");
			}
			else if(bu[i].charAt(0)=='A') {
				sb.append("A ");
			}
		}

		if(bu[bu.length-1].charAt(0)=='L') {
			sb.append("<");
		}
		else if(bu[bu.length-1].charAt(0)=='R') {
			sb.append(">");
		}
		else if(bu[bu.length-1].charAt(0)=='A') {
			sb.append("A");
		}
		System.out.println(sb.toString());
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