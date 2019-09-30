import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args){
		int MAXN = 10000000;
		boolean[] isp = new boolean[MAXN];
		Arrays.fill(isp, true);
		ArrayList<Long> P = new ArrayList<Long>();
		for(int i = 2; i < MAXN;i++){
			if(isp[i]){
				P.add((long)i);
				for(int j = 2*i; j < MAXN; j += i){
					isp[j] = false;
				}
			}
		}

		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T;zz++){
			long N = in.nextLong();
			long ans;
			if(N == 1)
				ans = 0;
			else
				ans = 1;
			for(long p:P){
				long q = p;
				int count = 0;
				while(q*p <= N){
					q *= p;
					count++;
				}
				if(count == 0){
					break;
				}
				ans += count;
			}
			System.out.format("Case #%d: %d\n", zz, ans);
		}
	}
}
