import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		System.out.println((a - b) % 2 == 0 ? "Alice" : "Borys");
	}
}