import java.util.Scanner;


public class D {
	private static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %s\n", i + 1, exec());
	}
	
	private static String exec() {
		int n = sc.nextInt();
		int count = 0;
		for (int i = 0; i < n; i++) if (sc.nextInt() != i + 1) count++;
		
		return Double.valueOf(count).toString();
	}
}
