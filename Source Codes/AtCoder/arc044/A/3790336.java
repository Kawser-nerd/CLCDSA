import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			int n = in.nextInt();
			if(judge(n)){
				System.out.println("Prime");
			}
			else {
				System.out.println("Not Prime");
			}
		}
	}
	
	public static boolean judge(int n){
		if(n == 1){
			return false;
		}
		boolean isPrime = true;
		for(int i=2; i*i<=n; i++){
			if(n % i == 0){
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			return true;
		}
		
		return (n % 2 != 0) && (n % 10 != 5) && (n % 3 != 0);
	}
}