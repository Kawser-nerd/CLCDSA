import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			ans += sc.nextInt() * sc.nextInt() / 10;
		}
		
		System.out.println(ans);
	}
}