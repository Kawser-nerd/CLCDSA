import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if (n == 0) {
			System.out.println(0);
			return;
		}
		
		StringBuilder sb = new StringBuilder();
		boolean isPlus = true;
		while (n != 0) {
			if (n % 2 != 0) {
				if (isPlus) {
					n -= 1;
				} else {
					n += 1;
				}
				sb.append(1);
			} else {
				sb.append(0);
			}
			n /= 2;
			isPlus = !isPlus;
		}
		System.out.println(sb.reverse());
	}
}