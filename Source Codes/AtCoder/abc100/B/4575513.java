import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int n = sc.nextInt();
		int ans = 0;
		if(n <= 99) {
			System.out.println(n * (int)Math.pow(100, d));
		}else {
			System.out.println(101 * (int)Math.pow(100, d));
		}
	}

}