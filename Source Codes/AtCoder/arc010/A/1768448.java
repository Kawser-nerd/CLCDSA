import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int[] c = new int[m];
		for(int i = 0 ; i < m ; i++) c[i] = sc.nextInt();
		for(int i = 0 ; i < m ; i++) {
			if(n <= a) {
				n += b;
			}
			n -= c[i];
			if(n < 0) {
				System.out.println(i + 1);
				return;
			}
		}
		System.out.println("complete");
	}
}