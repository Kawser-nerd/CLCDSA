import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		long n = scan.nextLong();
		long power = 1;

		for(int i = 1; i <= n; i++){
			power *= i;
			power %= 1000000007;
		}
		System.out.println(power);
	}
}