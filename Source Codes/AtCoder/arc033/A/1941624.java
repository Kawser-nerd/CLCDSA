import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = 0;
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 0 ; j <= n ; j++) {
				if(n >= i + j) ans++;
			}
		}
		System.out.println(ans);
	}
}