import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		String turn = "Ant";
		while(n > 0) {
			if(turn.equals("Ant")) {
				n -= a;
				turn = "Bug";
			} else {
				n -= b;
				turn = "Ant";
			}
		}
		if(turn.equals("Ant")) {
			System.out.println("Bug");
		} else {
			System.out.println("Ant");
		}
	}
}