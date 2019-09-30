import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T;zz++){
			int N = in.nextInt();
			int match = 0;
			for(int i = 0; i < N;i++)
				if(in.nextInt()-1 == i)
					match++;

			PROB = new double[N+1][N+1][2];
			for(double[][] a:PROB)
				for(double[] b:a)
					Arrays.fill(b, -1);
			double[] DP = new double[N+1];
			DP[N] = 0;
			for(int i = N-1; i>= 0; i--){
				int unmatched = N-i;
				for(int j = 1; j <= unmatched; j++){
					DP[i] += prob(unmatched, j, 0)*(1+DP[i+j]);
				}
				double probzero = prob(unmatched, 0, 0);
//				System.out.println("\t"+DP[i]+" "+probzero);
				DP[i] = (probzero+DP[i])/(1-probzero);
			}
//			System.out.println(Arrays.toString(DP));
			System.out.format("Case #%d: %.09f\n", zz, DP[match]);
		}
	}
	static double[][][] PROB;
	private static double prob(int total, int matched, int unmatch) {
		if(total < matched)
			return 0;
		if(matched < 0)
			return 0;
		if(total == 0 && matched == 0)
			return 1.0;
		if(PROB[total][matched][unmatch] != -1)
			return PROB[total][matched][unmatch];
		double ans = 0;
		if(unmatch == 0){
			double probhit = 1.0/total;
			ans += probhit * prob(total-1, matched-1, unmatch);
			ans += (1-probhit) * prob(total-1, matched, 1);
		}else{
			double probhit = 1.0/total;
			ans += probhit * prob(total-1, matched, 0);
			ans += (1-probhit) * prob(total-1, matched, 1);
		}
		PROB[total][matched][unmatch] = ans;
//		System.out.println("\t\t"+total+" "+matched+" "+unmatch+"\t"+ans);
		return ans;
	}
}
