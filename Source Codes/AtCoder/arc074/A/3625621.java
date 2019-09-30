import java.util.Scanner;
	

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		long min = Math.min(solve(H,W), solve(W,H));
		System.out.println(min);
	}

	private static long solve(long a, long b) {
		long min = 1000000000;
		min *= min;
		long d = b;
		for(long i=1;i<a;i++){
			long c = a-i;
			long size1 = i*b;
			if(b%2==0||c%2==0){
				long size2 = b*c/2;
				min = Math.min(min, Math.abs(size1-size2));
			}else{
				long e = c;
				d = Math.min(b, e);
				c = Math.max(b, e);
				long size2 = d*(c/2);
				long size3 = d*(c/2+1);
				long max = 0;
				max = Math.max(max, Math.abs(size1-size2));
				max = Math.max(max, Math.abs(size2-size3));
				max = Math.max(max, Math.abs(size3-size1));
				min = Math.min(min, max);
				
			}
		}
		return min;
	}
	
}