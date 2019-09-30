import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N+2];
		A[0] = 0;
		A[N+1] = 0;
		int max = 0;

		for(int i=1; i<N+1; i++) {
			A[i] = sc.nextInt();
			max += Math.abs(A[i] - A[i-1]);
		}
		max += Math.abs(A[N]);
		//System.out.println(max);
		for(int k=1; k<N+1; k++) {
			System.out.println(max-Math.abs(A[k]-A[k-1])
					-Math.abs(A[k+1]-A[k])
					+Math.abs(A[k+1]-A[k-1]));
		}

	}

}