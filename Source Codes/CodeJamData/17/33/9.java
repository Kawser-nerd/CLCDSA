import java.util.Arrays;
import java.util.Scanner;

public class ProblemC {
	
	public static void main(String[] args) throws Exception {
		
		try (Scanner sc = new Scanner(System.in)) 
		{
			int cases = sc.nextInt();
			
			for (int caseNum=1; caseNum<=cases; caseNum++)
			{
				solve(sc, caseNum);
			}
		}
	}
	
	static void solve(Scanner sc, int caseNum) 
	{
		int N = sc.nextInt();
		int K = sc.nextInt();
		double U = sc.nextDouble();
		double[] P = new double[N];
		for (int i=0; i<N; i++) {
			P[i] = sc.nextDouble();
		}
		Arrays.sort(P);
		double eps = 1e-8;
		for (int i=0; i<N-1; i++) {
			double add = P[i+1]-P[i];
			if (add*(i+1) > U + eps) {
				for (int j=0; j<=i; j++) {
					P[j]+=U/(i+1);
				}
				U=0;
				break;
			} else {
				for (int j=0; j<=i; j++) {
					P[j]+=add;
				}
				U-=add*(i+1);
			}
		}
		if (U>0) {
			for (int j=0; j<N; j++) {
				P[j]+=U/N;
			}
		}
		
		double res = 1;
		for (int j=0; j<N; j++) {
			res*=P[j];
		}
		
		System.out.printf("Case #%d: %.8f\n", caseNum, res);
	}
}
