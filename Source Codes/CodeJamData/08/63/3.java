import java.util.*;

public class C {
	static final int GOAL = 1000000;
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int N = sc.nextInt();
		for(int caseID = 1; caseID <= N; caseID++){
			int M = sc.nextInt();
			double p = sc.nextDouble();
			int X = sc.nextInt();
			double[][] table = new double[M + 1][(1 << M) + 1];
			for(int i = 0; i <= M; i++) Arrays.fill(table[i], -1.0);

			int unit = 1 << M;
			table[M][1 << M] = 1.0;
			table[M][0] = 0.0;
			for(int i = M - 1; i >= 0; i--){
				unit /= 2;
				for(int j = 0; j <= 1 << M; j += unit){
					double max = 0.0;
					if(j / unit % 2 == 0){
						for(int k = 0; j - k >= 0 && j + k <= 1 << M; k += 2 * unit){
							double val = p * table[i + 1][j + k] + (1.0 - p) * table[i + 1][j - k];
							max = Math.max(val, max);
						}
					}
					else{
						for(int k = unit; j - k >= 0 && j + k <= 1 << M; k += 2 * unit){
							double val = p * table[i + 1][j + k] + (1.0 - p) * table[i + 1][j - k];
							max = Math.max(val, max);
						}
					}
					table[i][j] = max;
				}
			}

			int IX = (int)(X * (1L << M) / GOAL);
			System.out.printf("Case #%d: %f%n", caseID, table[0][IX]);
		}
	}
}
