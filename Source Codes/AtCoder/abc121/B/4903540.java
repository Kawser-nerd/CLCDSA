import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int C = sc.nextInt();

		int[] bArray = new int[M];
		for(int i=0; i<M; i++) {
			bArray[i] = sc.nextInt();
		}


		int[][] aArray = new int[N][M];

		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				aArray[i][j] = sc.nextInt();
			}
		}

		int ans = 0;

		for(int i=0; i<N; i++) {
			int result=0;
			for(int j=0; j<M; j++) {
				result += aArray[i][j]*bArray[j];
			}
			ans += result + C >0 ? 1 : 0;
		}

		System.out.println(ans);
	}
}