import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int H,W,S,G;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		H=sc.nextInt();
		W=sc.nextInt();
		S=0;
		G=0;
		int[] xvec= {0,1,0,-1};
		int[] yvec= {-1,0,1,0};
		int[] zahyo=new int[H*W];
		int[] dist=new int[H*W];
		int[] isi=new int[H*W];
		int INF=1000000007;
		Arrays.fill(dist, INF);
		Arrays.fill(isi, INF);
		for(int i=0; i<H; i++) {
			String s=sc.next();
			for(int j=0; j<W; j++) {
				if(s.charAt(j)=='s') {
					S=i*W+j;
					zahyo[i*W+j]=0;
				}
				if(s.charAt(j)=='g') {
					G=i*W+j;
					zahyo[i*W+j]=0;
				}
				else if(s.charAt(j)=='#') {
					zahyo[i*W+j]=1;
				}
				else {
					zahyo[i*W+j]=0;
				}
			}
		}
		dist[S]=0;
		isi[S]=0;
		ArrayDeque<Integer> Q=new ArrayDeque<Integer>();
		Q.addFirst(S);
		while(!Q.isEmpty()) {
			int tmp=Q.pollFirst();
			for(int i=0; i<4; i++) {
				if(jyounai(tmp,xvec[i],yvec[i])) {		//????
					int coord=coord(tmp,xvec[i],yvec[i]);
					if(zahyo[coord]==0) {	//??????
						if(coord==G) {
							isi[coord]=isi[tmp];
							if(isi[coord]<=2) {
								pl("YES");
							}
							else {
								pl("NO");
							}
							System.exit(0);
						}
						if(dist[coord]==INF) {
							dist[coord]=dist[tmp]+1;
							Q.addFirst(coord);
							isi[coord]=isi[tmp];
						}
					}
					else if(zahyo[coord]==1) {	//???
						if(dist[coord]>dist[tmp]+1 && isi[coord]>isi[tmp]+1 && isi[tmp]+1<=2) {
							dist[coord]=dist[tmp]+1;
							Q.addLast(coord);
							isi[coord]=isi[tmp]+1;
						}
					}
				}
			}
		}
		pl("NO");
	}
	public static int coord(int a,int xv,int yv) {
		return a+yv*W+xv;
	}
	public static boolean jyounai(int a,int xv,int yv) {
		int y=a/W;
		int x=a%W;
		if(y+yv>=0 && y+yv<H) {
			if(x+xv>=0 && x+xv<W) {
				return true;
			}
		}
		return false;
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