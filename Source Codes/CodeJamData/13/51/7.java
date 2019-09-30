import java.math.BigDecimal;
import java.math.MathContext;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	static long money_counted(long[] A, int nuse, long min) {
		long money_counted = 0;
		for(int i=0; i<nuse; i++)
			money_counted += min-A[i];
		return money_counted;
	}
	static long money_used(long[] A, int nuse, long min) {
		long money_used = 0;
		for(int i=0; i<nuse; i++)
			money_used += min-A[i];
		for(int i=nuse; i<37; i++)
			if(A[i] <= min+1)
				money_used += min+1-A[i];
		return money_used;
	}
	static boolean OK(long[] A, long B, int nuse, long min) {
		return money_used(A,nuse,min) <= B;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			long B = in.nextLong();
			int n = in.nextInt();
			long[] A = new long[37];
			Arrays.fill(A, 0);
			for(int i=0; i<n; i++)
				A[i] = in.nextLong();
			Arrays.sort(A);

			BigDecimal ans = BigDecimal.ZERO;
			for(int nuse=1; nuse<=35; nuse++) {
				long lo = A[nuse-1];
				if(money_used(A,nuse,lo) > B) continue;
				long hi = 1000L*1000*1000*1000*100;
				while(lo < hi) {
					long mid = (lo+hi+1)/2;
					if(OK(A,B,nuse,mid))
						lo = mid;
					else hi = mid-1;
				}
				
				long money_counted = money_counted(A, nuse, lo);
				long money_used = money_used(A, nuse, lo);
				
				BigDecimal score = BigDecimal.valueOf(36).divide(BigDecimal.valueOf(nuse), MathContext.DECIMAL128).multiply(BigDecimal.valueOf(money_counted)).subtract(BigDecimal.valueOf(money_used));
				if(score.compareTo(ans)>0)
					ans = score;
				//ans = Math.max(ans, 36.0/nuse*money_counted - money_used);
				//System.out.println(nuse+" "+money_counted+" "+money_used+" "+ans);
			}
			/*
			for(int min=0; min<=2000; min++) {
				 int nmoney = (37-n)*min;
				 int nnum = 37-n;
				 for(int i=0; i<n; i++) {
					 if(min >= A[i]) {
						 nnum++;
						 nmoney += min-A[i];
					 }
				 }
				 
				 for(int delete=0; delete<=nnum; delete++) {
					 int money_spent = nmoney + delete;
					 int money_counted = nmoney - delete*min;
					 
					 int cnt = 0;
					 for(int i=0; i<n; i++) {
						 if(A[n-1-i]<=min && cnt<delete) {
							 cnt++;
							 money_counted += A[n-1-i];
						 }
					 }
					 
					 if(money_spent > B || nnum-delete==0) continue;
					 ans = Math.max(ans, (36.0/(nnum-delete+0.0))*money_counted-money_spent);
					 //System.out.println(min+" "+delete+" "+money_spent+" "+money_counted+" "+ans);
				 }
			}*/
			System.out.printf("Case #%d: %s\n", cas, ans.toPlainString());
		}
	}
}
