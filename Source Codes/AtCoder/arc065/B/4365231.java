import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	static int N,K,L;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		N=sc.nextInt();
		K=sc.nextInt();
		L=sc.nextInt();
		UnionFindTree uf=new UnionFindTree(N);
		int[] den=new int[N];
		for(int i=0;i<K; i++) {
			int f=sc.nextInt()-1;
			int t=sc.nextInt()-1;
			uf.unite(f,t);
		}
		for(int i=0; i<N; i++) {
			den[i]=uf.find(i);
		}
		uf=new UnionFindTree(N);
		int[] dou=new int[N];
		for(int i=0;i<L; i++) {
			int f=sc.nextInt()-1;
			int t=sc.nextInt()-1;
			uf.unite(f,t);
		}
		for(int i=0; i<N; i++) {
			dou[i]=uf.find(i);
		}
		HashMap<Long,Integer> num = new HashMap<Long,Integer>();
		long[] id=new long[N];
		for(int i=0; i<N; i++) {
			id[i]=((long)(den[i])*((long) N)+((long)(dou[i])));
			if(num.containsKey(id[i])) {
				num.put(id[i], num.get(id[i])+1);
			}
			else {
				num.put(id[i], 1);
			}
		}
		for(int i=0; i<N; i++) {
			if(i<N-1) {
				p(num.get(id[i])+" ");
			}
			else {
				p(num.get(id[i]));
			}
		}
		pl();
	}
	static class UnionFindTree {
		int[] root;
		int[] rank;

		UnionFindTree(int N){
			root = new int[N];
			rank = new int[N];
			for(int i=0;i<N;i++){
				root[i] = i;
			}
		}

		public int find(int x){
			if(root[x]==x){
				return x;
			}else{
				return find(root[x]);
			}
		}

		public void unite(int x,int y){
			x = find(x);
			y = find(y);
			if(x==y){
				return;
			}else{
				if(rank[x]<rank[y]){
					root[x] = y;
				}else{
					root[y] = x;
					if(rank[x]==rank[y]){
						rank[x]++;
					}
				}
			}
		}

		public boolean same(int x,int y){
			return find(x)==find(y);
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