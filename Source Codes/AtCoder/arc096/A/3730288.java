import java.util.*;
public class Main {
	
	public static void main(String... args) {
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		
		if (a + b > 2 * c) {
			int ans = 0;
			
			while(x >= 1 && y >= 1) {
				ans += 2*c;
				x-= 1;
				y-= 1;
			}
			
			if (x > 0 && a > 2*c) {
				while(x >= 1) {
					ans += 2*c;
					x -= 1;
				}
			}
			
			if (y > 0 && b > 2*c) {
				while(y >= 1) {
					ans += 2*c;
					y -= 1;
				}
			}
			
			ans += a*x + b*y;
			
			System.out.println(ans);
		} else {
			System.out.println(a*x + b*y);
		}
	}
}