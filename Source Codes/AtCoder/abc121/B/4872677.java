import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		int N=sc.nextInt();
		int M=sc.nextInt();
		int C=sc.nextInt();

		int count=0;
		int[] A=new int[M];
		int[] B=new int[M];

		for(int i=0;i<M;i++) {
			B[i]=sc.nextInt();
		}

		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				A[j]=sc.nextInt();
			}

			int sum=0;
			for(int k=0;k<M;k++) {
				sum+=A[k]*B[k];
			}
			sum+=C;

			if(sum>0) count++;


		}

		System.out.println(count);

		sc.close();

	}

}