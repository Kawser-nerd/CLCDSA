import java.io.PrintWriter;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int N = sc.nextInt();
		int[] x = new int[N];
		for(int i=0; i<N; i++)
			x[i] = sc.nextInt();
		int M = sc.nextInt();
		long K = sc.nextLong();
		int[] a = new int[M];
		for(int i=0; i<M; i++)
			a[i] = sc.nextInt()-1;
		
		int[] map = new int[N-1];
		for(int i=0; i<N-1; i++)
			map[i] = i;
		
		for(int i=0; i<M; i++) {
			int temp = map[a[i]-1];
			map[a[i]-1] = map[a[i]];
			map[a[i]] = temp;
		}
		
		int[] mapK = pow(map, K);
		
		long cur = x[0];
		for(int i=0; i<N; i++) {
			pw.println(cur);
			if(i<N-1)
				cur += x[mapK[i]+1]-x[mapK[i]];
		}
		
		sc.close();
		pw.close();
	}
	
	static int[] pow(int[] m, long K) {
		int[] ans = new int[m.length];
		for(int i=0; i<ans.length; i++)
			ans[i] = i;
		
		while(K>0) {
			if((K&1)!=0) {
				ans = mul(ans, m);
			}
			m = mul(m, m);
			
			K>>=1;
		}
		
		return ans;
	}
	
	static int[] mul(int[] a, int[] b) {
		int[] ans = new int[a.length];
		for(int i=0; i<ans.length; i++)
			ans[i] = a[b[i]];
		return ans;
	}
}