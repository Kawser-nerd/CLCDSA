import java.util.*;
public class Main {

	private static int X(int [] a, int [] b, int C) {
		int num = 0;
		int sum = C;
		for (int i = 0; i < a.length; i++) {
			sum += a[i] * b[i];

		}
		if (sum > 0)
			num = 1;
		return num;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int C = sc.nextInt();
		
		int [] A = new int [M];
		int [] B = new int [M];
		
		for ( int j = 0; j < M; j++) {
			B[j] = sc.nextInt();
		}
		int result = 0; 
		for ( int i = 0; i < N; i++) {
			for ( int j = 0; j < M; j++) {
				A[j] = sc.nextInt();
			}
			result += X(A, B, C);
		}
		
		System.out.println(result);
	}

}