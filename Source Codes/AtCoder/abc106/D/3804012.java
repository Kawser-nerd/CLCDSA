import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int Q = sc.nextInt();
		int[] L = new int[M];
		int[] R = new int[M];
		int[] p = new int[Q];
		int[] q = new int[Q];

		int[][] LR = new int[N+1][N+1];

		for(int i=0;i<M;i++){
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
			LR[L[i]][R[i]] +=1;
		}
		for(int i=0;i<Q;i++){
			p[i] = sc.nextInt();
			q[i] = sc.nextInt();
//			pq[][]
		}
		sc.close();

		for(int x=1; x<=N; ++x){
			for(int y=1; y<=N; ++y){
				LR[x][y] += LR[x][y-1] +LR[x-1][y] -LR[x-1][y-1];
			}
		}

		for(int i=0;i<Q;i++){
			int sum = LR[q[i]][q[i]] - LR[p[i]-1][q[i]] - LR[q[i]][p[i]-1] + LR[q[i]-1][p[i]-1];
			System.out.println(sum);
		}

	}

}