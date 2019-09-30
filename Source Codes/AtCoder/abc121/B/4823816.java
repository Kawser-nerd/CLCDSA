import java.util.Scanner;


public class Main {


	public static void main(String[] args) {
		// TODO ???????????????


		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int C = sc.nextInt();
		int res = 0;
		int[] B =new int[M] ;
		int[] A = new int[M];
		for(int i=0;i<M;i++) {
			B[i] = sc.nextInt();
		}
		for(int i = 0;i<N;i++) {
			int sum = C;
			for(int n = 0;n<M;n++) {
				A[n]=sc.nextInt();
			}
			for(int n = 0;n<M;n++) {
				sum += A[n]*B[n];
			}
			if(sum>0) {
				res++;
			}
		}
		System.out.println(res);
	}
}