import java.util.Scanner;

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int K = sc.nextInt();
		long[] x = new long[N];
		long[] y = new long[N];
		
		for(int i=0;i<N;i++){
			x[i] = sc.nextLong();
			y[i] = sc.nextLong();
		}
		
		long ans = 2000000000;
		ans *= ans;
		for(int i=0;i<N;i++){
			long x1 = x[i];
			for(int j=0;j<N;j++){
				long x2 = x[j];
				for(int k=0;k<N;k++){
					long y1 = y[k];
					for(int l=0;l<N;l++){
						long y2 = y[l];
						if(x1<x2 && y1<y2){
							int num = 0;
							
							for(int m=0;m<N;m++){
								if(x1<=x[m]&&x[m]<=x2&&y1<=y[m]&&y[m]<=y2){
									num++;
									
								}
								if(num>=K){
									ans = Math.min(ans,(x2-x1)*(y2-y1));
								}
							}
						}
					}
				}
			}
		}
		System.out.println(ans);
	}
	
}