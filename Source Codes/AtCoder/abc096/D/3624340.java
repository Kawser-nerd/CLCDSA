import java.util.Scanner;

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int i = 0;
		int K = 1;
		while(i<N){
			if(isPrime(5*K+1)){
				System.out.print((5*K+1 + " "));
				i++;
			}
			K++;
		}
	}

	private static boolean isPrime(int a) {
		
		for(int i=2;i*i<=a;i++){
			if(a%i==0){
				return false;
			}
		}
		return true;
	}
	
}