import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.HashMap;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		HashMap<String,Integer> siri=new HashMap<String,Integer>();
		String[] str=new String[N];
		for(int i=0; i<N; i++) {
			if(i==0) {
				str[i]=sc.next();
				siri.put(str[i],1);
			}
			else {
				str[i]=sc.next();
				if(str[i].charAt(0)!=str[i-1].charAt(str[i-1].length()-1)) {
					if(i%2==0) {
						pl("LOSE");
						System.exit(0);
					}
					else if(i%2==1) {
						pl("WIN");
						System.exit(0);
					}
				}
				else {
					if(siri.containsKey(str[i])) {
						if(i%2==0) {
							pl("LOSE");
							System.exit(0);
						}
						else if(i%2==1) {
							pl("WIN");
							System.exit(0);
						}
					}
					else {
						siri.put(str[i],1);
					}
				}
			}
		}
		pl("DRAW");
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