import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int n=s.nextInt(),a=s.nextInt(),b=s.nextInt();
		System.out.println(n<=5?n*b:5*b+(n-5)*a);
	}
}