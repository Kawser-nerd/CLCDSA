import java.util.Scanner;

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		
		long K = sc.nextLong();
		System.out.println(50);
		long P = K/50;
		long Q = K%50;
		for(long i=0;i<Q;i++){
			System.out.print((49-(Q-1)+P+50) +  " ");
		}
		for(long i=Q;i<50;i++){
			System.out.print((49-Q+P) +  " ");
		}
	}
	
}