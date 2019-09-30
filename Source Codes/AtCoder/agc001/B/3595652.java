import java.util.Scanner;

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		
		long N = sc.nextLong();
		long X = sc.nextLong();
		if(X*2>N){
			X = N - X;
		}
		N = N - X;
		long ans = 0;
		
		do{
			ans += (N/X)*X;
			long U = N%X;
			N = X;
			X = U;
		}while(X!=0);
		
		System.out.println(ans*3);
	}
	
}