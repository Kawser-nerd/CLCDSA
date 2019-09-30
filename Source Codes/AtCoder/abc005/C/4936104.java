import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0; i < N; i++)
			A[i] = sc.nextInt();
		int M = sc.nextInt();
		int[] B = new int[M];
		for(int i = 0; i < M; i++)
			B[i] = sc.nextInt();
		int length = 0;
		for(int i = 0; i < M; i++) {
			int s = B[i];
			while(true) {
				if(length >= N){
					System.out.println("no");
					return;
				}

				if(s < A[length] || s > A[length] + T) {
					length++;
					continue;
				}

				length++;
				break;
			}
		}

		System.out.println("yes");
	}

}