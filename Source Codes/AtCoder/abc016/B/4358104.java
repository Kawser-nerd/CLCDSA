import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		
		int A = sc.nextInt();
		int B = sc.nextInt();
		
		int R = sc.nextInt();
		
		boolean plus = A + B == R;
		boolean muinus = A - B == R;
		if (plus && muinus) {
			System.out.println("?");
		} else if (plus) {
			System.out.println("+");
		} else if (muinus) {
			System.out.println("-");
		} else {
			System.out.println("!");
		}
	}
	
}