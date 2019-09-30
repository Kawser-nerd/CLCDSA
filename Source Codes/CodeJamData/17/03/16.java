import java.util.*;
import java.math.*;

public class Main{

	void main2(int t, long N, long K){
		for(int step=0;;step++){
			long groups = (1l<<step);
			if(K > groups){
				K -= groups;
				continue;
			}
			
			long small = N / groups;
			long big = small + 1;
			long bigcnt = N % groups;
			long smallcnt = groups - bigcnt;
			
			long x = big;
			if(K > bigcnt) x = small;
			
			System.out.printf("Case #%d: %d %d\n", t, (x + 1) / 2 - 1, x / 2 - 1);
			
			return;
		}
	}

	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t=0;t<T;t++){
			long N = scan.nextLong();
			long K = scan.nextLong();
			(new Main()).main2(t+1, N+1, K);
		}
	}

}
