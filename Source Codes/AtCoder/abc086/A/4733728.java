import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b, c;
		a = sc.nextInt();
		b = sc.nextInt();
		c = a * b;
		if (c % 2 == 0) {
			System.out.println("Even");
		} else {
			System.out.println("Odd");
		}
		sc.close();
	}

}