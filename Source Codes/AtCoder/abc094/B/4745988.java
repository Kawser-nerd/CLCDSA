import java.util.Scanner;
 
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int count = 0;
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			if (a < x) {
				count++;
			} 
		}
		System.out.println(Math.min(count, m - count));
	}
}