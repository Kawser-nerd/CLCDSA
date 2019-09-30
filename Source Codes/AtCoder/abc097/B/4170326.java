import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int max = 1;
		for (int i = 2; i <= 100; i++) {
			for (int j = 2; j < 10; j++) {
				int target = (int)Math.pow(i, j);
				if (target > x) {
					break;
				}
				if (target > max) {
					max = target;
				}
			}
		}
		System.out.println(max);
	}
}