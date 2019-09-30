import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T; zz++){
			String S = in.next();
			long v = 0;
			long nv = 0;
			for(int i = 0; i < S.length();i++){
				int at = S.length()-i-1;
				if(S.charAt(i) == '?'){
					nv |= 1L << at;
				}else if(S.charAt(i) == '1'){
					v |= 1L << at;
				}
			}
			long ans = 0;
			for(long c = nv; ; c = (c-1)&nv){
				long test = v+c;
				if(issquare(test)){
					ans = test;
					break;
				}
				if(c == 0)
					break;
			}
			System.out.format("Case #%d: %s\n", zz, Long.toBinaryString(ans));
		}
	}

	private static boolean issquare(long t) {
		long low = 1;
		long high = Integer.MAX_VALUE;
		while(low <= high){
			long mid = (low+high)/2;
			long v = mid*mid;
			if(v == t){
				return true;
			}
			if(v < t){
				low = mid+1;
			}else{
				high = mid-1;
			}
		}
		return false;
	}
}
