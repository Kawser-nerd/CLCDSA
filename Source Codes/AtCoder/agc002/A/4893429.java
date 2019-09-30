import java.util.*;

public class Main {
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		String ans = null;
		if (b > 0) {
			if (a > 0) {
				ans = "Positive";
			} else {
				ans = "Zero";
			}
		} else if (b == 0) {
			ans = "Zero";
		} else {
			int x = a - b;
			if (x % 2 == 0) {
				ans = "Negative";
			} else {
				ans = "Positive";
			}
		}
		System.out.print(ans);
	}
}