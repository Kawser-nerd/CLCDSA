import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int a = Math.abs(sc.nextInt());
		int b = Math.abs(sc.nextInt());
		if (a<b) System.out.println("Ant");
		if (a>b) System.out.println("Bug");
		if (a==b) System.out.println("Draw");
	}
}