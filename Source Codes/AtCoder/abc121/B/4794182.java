import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();
		int C = sc.nextInt();

		int[] B = new int[M];

		for(int i = 0 ; i < M ; i++){
			B[i] = sc.nextInt();
		}

		int[] A = new int[N*M];
		for(int i = 0 ; i < N*M ; i++){
			A[i] = sc.nextInt();
		}

		sc.close();

		int[] calc = new int[M];

		int tmp = 0;
		int ans = 0;
		int p = 0;
		for(int i = 0 ; i < M*N ; i=i+M){
			for(int k = 0 ; k < M ; k++){
				tmp = tmp + B[k]*A[i+k];
			}
			if(tmp+C > 0){
				ans = ans + 1;
			}
			tmp = 0;
		}
		System.out.println(ans);
	}
}