import java.util.*;

class Main{
	public static void main(String args[]){
		int N,M,A,B;
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		A = sc.nextInt();
		B = sc.nextInt();
		
		int[] c = new int[M];
		
		for(int i=0;i<M;i++){
			c[i] = sc.nextInt();
		}
		
		for(int i=0;i<M;i++){
			if(N <= A){
				N += B;
			}
			
			N = N - c[i];
			
			
			if(N < 0){
				System.out.println(i + 1);
				return;
			}
		}
		
		System.out.println("complete");
	}
}