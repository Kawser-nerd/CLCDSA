import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int[] arr=new int[N];
		int counter=0;
		/*
		 * ?????????????
		 *
		 *
		 *
		 */
		ArrayList<Integer> ary=new ArrayList<Integer>();
		for(int i=0; i<N; i++) {
			ary.add(sc.nextInt());
		}
		boolean dekiru=true;

		for(int i=0; i<N; i++) {
			int basyo=0;
			int num=0;
			for(int j=0; j<ary.size(); j++) {
				if(j+1==ary.get(j)) {
					if(ary.get(j)>num) {
						basyo=j;
						num=ary.get(j);
					}
				}
			}
			if(num>0) {
				ary.remove(basyo);
				arr[N-1-counter]=num;
				counter++;
			}

		}
		if(ary.size()==0) {
			for(int i=0; i<N; i++) {
				pl(arr[i]);
			}
		}
		else {
			pl(-1);
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