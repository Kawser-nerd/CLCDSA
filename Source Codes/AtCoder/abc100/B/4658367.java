import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int n = sc.nextInt();
		if (n == 100) {
			System.out.println((long)(Math.pow(100, d)) * 101);
		}
		else {
			System.out.println((long)(Math.pow(100, d)) * n);
		}
	}

}