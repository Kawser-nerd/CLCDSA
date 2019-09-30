import java.util.*;
public class Main{
	static int n;
	static long[] h = new long[1000000];
	static long[] s = new long[1000000];

	static boolean check(long H){
		long[] t = new long[n];
		for(int i=0; i<n; i++){
          	if(H < h[i])return false;
			t[i] = (H - h[i]) / s[i];
		}
		Arrays.sort(t);
		for(int i=0; i<n; i++){
			if(t[i]<i)return false;
		}
		return true;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		for(int i=0; i<n; i++){
			h[i] = sc.nextLong();
			s[i] = sc.nextLong();
		}
		long ok = 10000000000000000L;
		long ng = -1;
		while(ok-ng > 1){
			long mid = (ok+ng) / 2;
			if(check(mid)){
				ok = mid;
			}
			else{
				ng = mid;
			}
		}
		System.out.println(ok);
	}
}