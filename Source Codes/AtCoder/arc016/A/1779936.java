import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] x = new int[n];
		for(int i = 0 ; i < n ; i++) x[i] = i + 1;
		for(int i = 0 ; i < n ; i++) {
			if(x[i] != m) {
				System.out.println(x[i]);
				return;
			}
		}
	}
}