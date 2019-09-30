import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	static boolean OK;
	static boolean[][] path;
	static boolean[] visited;
	static int N;
	static int ans=0;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		N=sc.nextInt();
		int M=sc.nextInt();
		path=new boolean[N][N];
		visited=new boolean[N];
		for(int i=0; i<M; i++) {
			int f=sc.nextInt()-1;
			int t=sc.nextInt()-1;
			path[t][f]=true;
			path[f][t]=true;
		}
		for(int i=0; i<N; i++) {
			if(!visited[i]) {
				OK=true;
				visited[i]=true;
				dfs(i);
				if(OK){
				ans++;
				}
			}
		}
		pl(ans);
	}
	static void dfs(int v) {
		for(int i=0; i<N; i++) {
			if(!visited[i] && path[v][i]) {
				path[v][i]=false;
				path[i][v]=false;
				visited[i]=true;
				dfs(i);
			}
			else if(visited[i] && path[v][i]){
				path[v][i]=false;
				path[i][v]=false;
				OK=false;
			}
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
}