import java.util.Scanner;

public class Main{
	
	public static void main(String args[])throws Exception{
		
		Scanner sc= new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] B = new int[N];
		int[] p = new int[N];
		int[] q = new int[N];
		for(int i=0;i<N;i++){
			p[i] = sc.nextInt();
			q[p[i]-1] = i+1;
		}
		A[0] = q[0];
		B[0] = 0;
		for(int i=1;i<N;i++){
			if(q[i-1]<q[i]){
				B[i] = B[i-1]-1;
				A[i] = q[i] - B[i];
			}else{
				A[i] = A[i-1] + 1;
				B[i] = q[i] - A[i];
			}
		}
		
		for(int i=0;i<N;i++){
			System.out.print(A[i] + " ");
		}
		System.out.println();
		for(int i=0;i<N;i++){
			System.out.print((B[i]+1000000000) + " ");
		}

	}
}