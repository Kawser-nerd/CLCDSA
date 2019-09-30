import java.util.Scanner;

public class Main{
	public static void main(String args[])throws Exception{

		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		if(a * b <= 0) {
			System.out.println("Zero");
		}
		else if(a < 0 && b < 0 && (b-a)% 2 == 0) {
			System.out.println("Negative");
		}else {
			System.out.println("Positive");
		}
	}
}