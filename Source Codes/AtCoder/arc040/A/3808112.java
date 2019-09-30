import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long red = 0;
		long blue = 0;
		for(int i = 0; i < n; i++) {
			String s = sc.next();
			for(char c : s.toCharArray()) {
				if(c == 'R') {
					red++;
				} else if(c == 'B') {
					blue++;
				}
			}
		}
		System.out.println(red==blue ? "DRAW" : red>blue ? "TAKAHASHI" : "AOKI");
	}
}