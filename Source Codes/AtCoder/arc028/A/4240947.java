import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int mod = n % (a + b);
		if (mod <= a && mod != 0) {
			System.out.println("Ant");
		}else {
			System.out.println("Bug");
		}
	}
}