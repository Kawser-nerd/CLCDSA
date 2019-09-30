import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int a = sc.nextInt();
		int b = sc.nextInt();
		if (a<0) a++;
		if (b<0) b++;
		System.out.println(b-a);
	}
}