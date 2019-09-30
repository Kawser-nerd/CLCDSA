import java.util.Scanner;

public class Main{
	
	public static void main(String args[])throws Exception{
		
		Scanner sc= new Scanner(System.in);
		int N = sc.nextInt();
		long x = sc.nextLong();
		long[] a = new long[N+1];
		for(int i=1;i<=N;i++){
			a[i] = sc.nextInt();
		}
		long[][] partmin = new long [N+1][N+1];
		
		for(int i=1;i<=N;i++){
			for(int j=i;j<=N+i-1;j++){
				if(i==j){
					partmin[i][j] = a[i];
				}else{
					int k = (j-1)%N+1;
					if(k!=1){
						partmin[i][k] = Math.min(partmin[i][k-1], a[k]);
					}else{
						partmin[i][k] = Math.min(partmin[i][N],a[1]);
					}
				}
			}
		}
		
		long min = 1000000000;
		min = min * min;
		
		
		for(long i=0;i<N;i++){
			long cost = i * x;
			for(int j=1;j<=N;j++){
				cost += partmin[(int)(N+j-i-1)%N+1][j];
				
				
			}
			min = Math.min(min, cost);
		}
		
		System.out.println(min);
	}
}