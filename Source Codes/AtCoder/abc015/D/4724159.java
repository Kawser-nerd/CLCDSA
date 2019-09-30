import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int W = Integer.parseInt(sc.next());
		int N = Integer.parseInt(sc.next());
		int K = Integer.parseInt(sc.next());
		int[] A = new int[N];
		int[] B = new int[N];
		
		for(int i=0; i<N; i++){
			A[i] = Integer.parseInt(sc.next());
			B[i] = Integer.parseInt(sc.next());
		}
		
		int[][][] dp = new int[N+1][W+1][K+2];
		
		for(int i=0; i<N; i++){
			for(int w=0; w<=W; w++){
				for(int k=0; k<=K; k++){
					if(w>=A[i] && dp[i][w][k] < dp[i][w-A[i]][k] + B[i]){
						dp[i+1][w][k+1] = Math.max(dp[i][w][k+1], dp[i][w-A[i]][k] + B[i]);
					}else{
						dp[i+1][w][k] = Math.max(dp[i+1][w][k], dp[i][w][k]);
					}
				}
			}
		}
		
		System.out.println(dp[N][W][K]);
		
		sc.close();
	}
	
}