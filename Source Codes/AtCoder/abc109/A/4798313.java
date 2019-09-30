import java.util.Scanner;

public class Main {
	public static long MOD = 1000000007l;

	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		System.out.println(a*b%2==0 ? "No" : "Yes");
	}
}