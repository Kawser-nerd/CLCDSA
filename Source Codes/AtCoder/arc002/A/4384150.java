import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int y = sc.nextInt();
		boolean uruu = false;
		if (y % 400 == 0) {
			uruu = true;
		} else if (y % 100 != 0 && y % 4 == 0) {
			uruu = true;
		}
		if (uruu) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}