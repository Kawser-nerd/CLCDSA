import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int h = sc.nextInt();
		int w = sc.nextInt();
		System.out.println((h-1)*w+h*(w-1));
	}
}