import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main {
	static int ax;
	static int ay;
	static int bx;
	static int by;

	public static void main(String[] args) {
		SC sc = new SC(System.in);
		ax=sc.nextInt();
		ay=sc.nextInt();
		bx=sc.nextInt();
		by=sc.nextInt();
		int N=sc.nextInt();
		int[][] zahyo=new int[N][2];
		for(int i=0; i<N; i++) {
			zahyo[i][0]=sc.nextInt();
			zahyo[i][1]=sc.nextInt();
		}
		int point=0;
		for(int i=0; i<N; i++) {
			if(Crossing(zahyo[i][0],zahyo[i][1],zahyo[(i+1)%N][0],zahyo[(i+1)%N][1])) {
				point++;
			}
		}
		pl(point/2+1);
	}

	public static boolean Crossing(int px, int py, int qx, int qy) {
		long t1 = ((py - ay) * (bx - ax) - (px - ax) * (by - ay));
		long t2 = ((qy - ay) * (bx - ax) - (qx - ax) * (by - ay));
		long t3 = ((ay - py) * (qx - px) - (ax - px) * (qy - py));
		long t4 = ((by - py) * (qx - px) - (bx - px) * (qy - py));
		return t1 * t2 < 0 && t3 * t4 < 0;
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