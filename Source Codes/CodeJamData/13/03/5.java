import java.util.*;
import java.math.*;

public class C{

	int sz;
	BigInteger good[] = new BigInteger[50000];
	BigInteger ten[] = new BigInteger[110];
	
	public boolean check(int[] a){
		int N=a.length,i,j;
		int b[] = new int[2*N-1];
		for(i=0;i<N;i++) for(j=0;j<N;j++) b[i+j] += a[i] * a[j];
		for(i=0;i<2*N-1;i++) if(b[i] >= 10) return false;
		return true;
	}
	
	public void dfs(BigInteger N, int[] a, int L, int R){
		int i;
		
		if(!check(a)) return;
		
		if(L >= R){
			good[sz] = N.multiply(N);
			sz++;
			return;
		}
		
		for(i=0;i<=3;i++) if(i != 0 || L != 0){
			BigInteger M = N;
			M = M.add(BigInteger.valueOf(i).multiply(ten[L]));
			if(R-1 != L) M = M.add(BigInteger.valueOf(i).multiply(ten[R-1]));
			a[L] = a[R-1] = i;
			dfs(M, a, L+1, R-1);
			a[L] = a[R-1] = 0;
		}
	}

	void main2(){
		int T,t,i;
		
		ten[0] = BigInteger.ONE;
		for(i=1;i<110;i++) ten[i] = ten[i-1].multiply(BigInteger.valueOf(10));
		
		for(i=1;i<=50;i++){
			int a[] = new int[i];
			dfs(BigInteger.ZERO, a, 0, i);
		}
		
		Scanner scan = new Scanner(System.in);
		T = scan.nextInt();
		
		for(t=1;t<=T;t++){
			BigInteger A = new BigInteger(scan.next());
			BigInteger B = new BigInteger(scan.next());
			int ans = 0;
			for(i=0;i<sz;i++) if(good[i].compareTo(A) >= 0 && good[i].compareTo(B) <= 0) ans++;
			System.out.printf("Case #%d: %d\n", t, ans);
		}
	}

	public static void main(String args[]){
		(new C()).main2();
	}

}
