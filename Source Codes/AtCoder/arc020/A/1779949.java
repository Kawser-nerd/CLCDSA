import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		if(Math.abs(n) < Math.abs(m)) {
			System.out.println("Ant");
		} else if(Math.abs(n) > Math.abs(m)) {
			System.out.println("Bug");
		} else {
			System.out.println("Draw");
		}
	}
}