import java.util.Scanner;


public class C {
	private static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %s\n", i + 1, exec());
	}
	
	private static String exec() {
		int n = sc.nextInt();
		int[] candy = new int[n];
		for (int i = 0; i < n; i++) candy[i] = sc.nextInt();
		
		return calc(candy);
	}
	
	private static String calc(int[] candy) {
		int xor = 0;
		int smallest = Integer.MAX_VALUE;
		int sum  = 0;
		for (int c : candy) {
			if (smallest > c) smallest = c;
			xor ^= c;
			sum += c;
		}
		
		if (xor != 0) return "NO";
		return "" + (sum - smallest);
	}
}
