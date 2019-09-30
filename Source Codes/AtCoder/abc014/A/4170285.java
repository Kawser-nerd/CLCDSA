import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt();
		int mod = a % b;
		System.out.println(mod != 0 ? b - mod : 0);
	}
}