import java.util.*;
import java.io.*;

public class Main {
	private static void solve(){
		//Implement solution here.
		int n = ni();
		int m = ni();
		int[] aa = new int[m];
		int[] ba = new int[m];
		UnionFind uf = new UnionFind(n + 1);

		long result = (long)n*(n-1)/2;
		Deque<Long> resultq = new ArrayDeque<>();
		resultq.push(result);

		for(int i = 0; i < m; i++){
			aa[i] = ni();
			ba[i] = ni();
		}

		for(int i = m - 1; i > 0; i--){

			if(!uf.sameGroup(aa[i], ba[i])) {
				result -= (long)uf.size[uf.find(aa[i])] * uf.size[uf.find(ba[i])];
			}
			uf.unite(aa[i], ba[i]);
			resultq.push(result);			
		}

		while(!resultq.isEmpty()){
			System.out.println(resultq.pop());
		}
	}

	static class UnionFind{
		//Union find tree.
		private int[] par;
		private int[] rank;
		public int g;
		public int[] size;

		public UnionFind(int size) {
			this.par = new int[size];
			this.rank = new int[size];
			this.size = new int[size];
			for(int i = 0; i < size; i++) {
				par[i] = i;
				rank[i] = 0;
				this.size[i] = 1;
			}
			this.g = size;

			Arrays.fill(this.size, 1);
		}

		public int find(int x) {
			if(par[x] == x) {
				return x;
			} else {
				return find(par[x]);
			}
		}

		public void unite(int x, int y) {
			int xpar = find(x);
			int ypar = find(y);
			if(xpar == ypar) {
				return;
			}else {
				int sum = size[xpar] + size[ypar];
				size[xpar] = sum;
				size[ypar] = sum;
				
				if(rank[xpar] < rank[ypar]) {
					par[xpar] = ypar;
				} else {
					par[ypar] = xpar;
					if(rank[xpar] == rank[ypar]) rank[xpar] ++;
				}
			}
		}

		public boolean sameGroup(int x, int y) {
			return find(x) == find(y);
		}		
	}


	//Switch input source (stdin/file)
	private static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args){
		String debugDataPath = System.getenv("DD_PATH");        
		if(debugDataPath != null){
			try{
				scanner = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(new File(debugDataPath)))));
			}catch(Exception e){
				throw new RuntimeException(e);
			}
		}
		solve();
	}

	//Input read utility
	private static StringTokenizer tokenizer = null;
	public static String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(scanner.nextLine());
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}
	//Get next single int
	private static int ni() {
		return Integer.parseInt(next());
	}
	//Get next single long
	private static long nl() {
		return Long.parseLong(next());
	}
	//Get next single double
	private static double nd() {
		return Double.parseDouble(next());
	}
	//Get next int array from one line
	private static int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}
	//Get next char array from one line
	private static char[] ns() {
		return next().toCharArray();
	}
	//Get next long array from one line
	private static long[] nal(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nl();
		return a;
	}
}