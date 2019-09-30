import java.util.Scanner;

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int Ma = sc.nextInt();
		int Mb = sc.nextInt();
		int[] a = new int[N+1];
		int[] b = new int[N+1];
		int[] c = new int[N+1];
		for(int i=1;i<N+1;i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
			
			
		}
		int[][][] cost = new int[N+1][500][500];
		for(int i=0;i<N+1;i++){
			for(int j=0;j<500;j++){
				for(int k=0;k<500;k++){
					cost[i][j][k] = 5000;
				}
			}
		}
		
		cost[0][0][0] = 0;
		
		for(int i=1;i<N+1;i++){
			for(int j=0;j<500;j++){
				for(int k=0;k<500;k++){
					if(j>=a[i]&&k>=b[i]){
						cost[i][j][k] = Math.min(cost[i-1][j][k], cost[i-1][j-a[i]][k-b[i]]+c[i]);
					}else{
						cost[i][j][k] = cost[i-1][j][k];
					}
				}
			}
		}
		
		int ans = 5000;
		
		for(int i=1;i<=500;i++){
			if(i*Ma<500&&i*Mb<500){
				ans = Math.min(ans,cost[N][i*Ma][i*Mb]);
			}
		}
		if(ans==5000){
			ans=-1;
		}
		System.out.println(ans);
	}
	
}