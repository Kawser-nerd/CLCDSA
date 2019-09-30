import java.util.Scanner;
	

public class Main{
	
	
	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		long A = sc.nextLong();
		long B = sc.nextLong();
		long[] h = new long[N];
		for(int i=0;i<N;i++){
			h[i] = sc.nextLong();
		}
		
		long ok = 1000000000;

		long ng = 0;
		
		while(Math.abs(ok-ng)>1){
			long mid = (ok+ng)/2;
			long solo = A-B;
			long time = 0;
			for(int i=0;i<N;i++){
				if(B*mid<h[i]){
					time += (h[i]-mid*B-1)/solo +1;
				}
			}
			if(time>mid){
				ng = mid;
			}else{
				ok = mid;
			}
		}
		
		System.out.println(ok);
	}
	

}