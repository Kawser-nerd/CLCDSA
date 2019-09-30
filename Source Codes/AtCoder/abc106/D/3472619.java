import java.util.Scanner;

class Main{

	static int N;
	static long M;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);			//?????

		int N = sc.nextInt();
		int M = sc.nextInt();
		int Q = sc.nextInt();
		int[] L  = new int[M];
		int[] R  = new int[M];

		int[][] memo = new int[N+1][N+1];

		for(int i= 0;i < M;i++){
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
			memo[L[i]][R[i]]++; 
		}

		int[][] dp = new int[N+1][N+1];

		for(int i = 1;i <= N;i++){
			for(int j = 1;j <= N;j++){
				dp[i][j] = dp[i][j-1] + memo[i][j];
			}
		}


		for(int i= 1;i <= Q;i++){
			int	p = sc.nextInt();
			int	q = sc.nextInt();
			int sum = 0;
			for(int j = p;j <= q;j++){
				sum += (dp[j][q] - dp[j][p-1]);
			}

			System.out.println(sum);
		}



	}


}