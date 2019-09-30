import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t = 1; t <= T;t++){
			int D = sc.nextInt();
			int I = sc.nextInt();
			int M = sc.nextInt();
			int N = sc.nextInt();
			int[] A = new int[N];
			for(int i = 0; i < N;i++)
				A[i] = sc.nextInt();
			int[] DP = new int[256];
			Arrays.fill(DP,0);
			int[] CUR = new int[256];
			for(int at = N-1; at >= 0; at--){
				for(int i = 0; i < 1000;i++){
					int prev;
					if(i%2 == 0)
						prev = A[at]+i/2;
					else
						prev = A[at]-(i+1)/2;
					if (prev < 0 || prev >= 256)
						continue;

					int cost = DP[prev]+D;
					for(int j = 0; j < 256;j++){
						if(abs(j-prev) <= M || prev == -1)
							cost = min(cost,DP[j] + abs(j-A[at]));
						if(abs(j-A[at]) < abs(A[at]-prev) && (prev == -1 || abs(j-prev) <= M))
							cost = min(cost,CUR[j]+I);
					}
					CUR[prev] = cost;
				}
				for(int j = 0; j < 256;j++)
					DP[j] = CUR[j];
				Arrays.fill(CUR,0);
			}
			int ans = Integer.MAX_VALUE;
			for(int i = 0; i < DP.length;i++)
				ans = min(ans,DP[i]);
			System.out.format("Case #%d: %d\n", t,ans);

		}
	}
}
