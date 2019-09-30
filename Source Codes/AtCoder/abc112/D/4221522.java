import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int ans = 1;
		for(int i = (M / N); i >= 1; i--) {
			if(M % i == 0) {
				ans = i;
				break;
			}
		}
		System.out.println(ans);
	}
}