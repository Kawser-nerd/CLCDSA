import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n =sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		n = n % (a+b);
		if(n==0) {
			System.out.println("Bug");
			return;
		}
		System.out.println(n > a ? "Bug" : "Ant");
	}
}