import java.util.*;

public class DeceitfulWar {
	static int[][] memo;
	static int[] u,v;
	static int N;
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = N = reader.nextInt();
			int[] naomi = u = new int[n];
			int[] ken = v = new int[n];
			for(int i = 0; i < n; i++)
				naomi[i] = (int)Math.round(reader.nextDouble() * 1e7);
			for(int i = 0; i < n; i++)
				ken[i] = (int)Math.round(reader.nextDouble() * 1e7);
			Arrays.sort(naomi);
			Arrays.sort(ken);
			compress(naomi,ken);
			
			int war = 0;
			int a = n-1;
			int b = 0;
			int c = n-1;
			while(b <= c){
				if(naomi[a--] > ken[c]){
					war++;
					b++;
				}else
					c--;
			}
			
			memo = new int[n+1][n+1];
			for(int[] m:memo)Arrays.fill(m,-1);
			
			System.out.println("Case #"+t+": "+f(0,n) + " " + war);
		}
	}
	
	public static int f(int n, int m){
		if(memo[n][m] == -1){
			if(n == m){
				memo[n][m] = 0;
			}else{
				int k = n + (N-m);
				int max = f(n,m-1);
				if(u[k] > v[n])
					max = Math.max(max, 1 + f(n+1,m));
				memo[n][m] = max;
			}
		}
		return memo[n][m];
	}
	
	public static void compress(int[] x, int[] y){
		int a = 0;
		int b = 0;
		int cnt = 0;
		while(a < x.length || b < y.length){
			if(b == y.length || (a < x.length && x[a] < y[b]))
				x[a++] = cnt++;
			else
				y[b++] = cnt++;
		}
	}
}
