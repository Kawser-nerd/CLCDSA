import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int N=sc.nextInt();
		String S=sc.next();
		Deque<Integer> tmp=new ArrayDeque<Integer>();
		for(int i=0; i<N; i++) {
			if(S.charAt(i)=='(') {
				tmp.push(0);
			}
			else if(S.charAt(i)==')') {
				if(tmp.size()==0) {
					tmp.push(1);
				}
				else {
					if(tmp.size()==0) {
						tmp.push(1);
					}
					else {
						if(tmp.peek()==0) {
							tmp.remove();
							//pl("!");
						}
						else {
							tmp.push(1);
							//pl("?");
						}
					}
				}
			}
		}
		int mae=0;
		int ato=0;
		int size=tmp.size();
		//pl(size);
		for(int i=0; i<size; i++) {
			int get=tmp.poll();
			if(get==0) {
				ato++;
			}
			else if(get==1) {
				mae++;
			}
		}
		StringBuilder sb=new StringBuilder();
		for(int i=0; i<mae; i++) {
			sb.append("(");
		}
		sb.append(S);
		for(int i=0; i<ato; i++) {
			sb.append(")");
		}
		pl(sb.toString());

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