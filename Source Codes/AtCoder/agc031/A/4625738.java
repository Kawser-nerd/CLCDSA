import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer>[]ed;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n=sc.nextInt();
		String s=sc.nextLine();
		long ans=1;
		int []a=new int[26];
		Arrays.fill(a,1);
		for(int i=0;i<n;i++)
			a[s.charAt(i)-'a']++;
		for(int i=0;i<26;i++) {
			ans=(ans*a[i])%mod;
		}
		ans--;
		out.print(ans);
		out.flush();
	}
	static final long mod=(long)1e9+7;
	static long fac(long n) {
		if(n==0 || n==1)
			return 1;
		long a=1;
		while(n>0) {
			a*=n;
			n--;
		}
		return a;
	}
	static boolean io=false;
	static boolean []vis;
    static void dfs(int u,int w) {
    	vis[u]=true;
    	if(u==w)
    		 io=true;
    	for(int v:ed[u]) {
    		if(!vis[v]) {
    	   dfs(v,w);
    		}
    	}
    	//return false;
    }
	static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	static class pair{
		char a;
	    char b;

		pair(char a,char b) {
			this.a = a;
			this.b = b;
		}

		public String toString() {
			return a + " " + b;
			}
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}

		public Scanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public char nextChar() throws IOException {
			return next().charAt(0);
		}

		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}