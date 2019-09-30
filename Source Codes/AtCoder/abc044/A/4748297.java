import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		int x = scan.nextInt();
		int y = scan.nextInt();
			
		int sum = 0;

		if(n <= k){
			sum = n * x;
		}

		else{
			sum = k * x;
			sum = sum + ((n - k) * y);
		}

		System.out.println(sum);
	}
}