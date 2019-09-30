import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		HashMap<Integer, ArrayList<Integer>> m = new HashMap<Integer, ArrayList<Integer>>();
		int N = sc.nextInt();
		int M = sc.nextInt();
		for(int i=0; i<N; i++) {
			m.put(i+1, new ArrayList<Integer>());
		}
		for(int i=0; i<M; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			m.get(a).add(b);
			m.get(b).add(a);
		}
		for(int e : m.get(1)) {
			if(m.get(e).contains(N)) {
				print("POSSIBLE");
				return;
			}
		}
		print("IMPOSSIBLE");
	}
	
	// print
	static void print(String s) {
		System.out.println(s);
	}
	
	// union find lib
	// usage:
	// ???init???
	// root: ????????
	// unite: ????
	// same: ??????
	static void init(int par[], int N) {
		for(int i=0; i<N; i++) {
			par[i] = i;
		}
	}
	
	static int root(int x, int [] par) {
		if(par[x] == x) {
			return x;
		} else {
			return (par[x] = root(par[x], par));
		}
	}
	
	static boolean same(int x, int y, int[] par) {
		return root(x, par) == root(y, par);
	}
	
	static void unite(int x, int y, int[] par) {
		x = root(x, par);
		y = root(y, par);
		if(x == y) return;
		par[x] = y;
	}
	
	// end union find lib
	
	// number lib
	
	static long lcm(long a, long b) {
		return a*(b/gcd(a, b));
	}
	
	static long gcd(long a, long b) {
		long ta = Math.max(a, b);
		long tb = Math.min(a, b);
		long tmp;
		while((tmp = ta%tb) != 0) {
			ta = tb;
			tb = tmp;
		}
		return tb;
	}
	
	static long modcomb(long n, long k, long mod) {
		if(k==1) {
			return n;
		}
		
		long ans = 1;
		for(long i=n; i>=n-k+1; i--) {
			ans = (ans * i)%mod;
		}
		for(long i=k; 0<i; i--) {
			ans = (ans * modpow(i, mod-2, mod)) % mod;
		}
		return ans;
	}
	
	static long modpow(long a, long b, long mod) {
		if(b==0) return 1;
		if(b%2==0) {
			long d = modpow(a, b/2, mod);
			return (d*d)%mod;
		} else {
			return (a*modpow(a, b-1, mod))%mod;
		}
	}
	
	static int disit(long a, long d) {
		int count = 0;
		while(a!=0) {
			a = a/d;
			count++;
		}
		return count;
	}
	
	// end number lib
}