import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int limit = sc.nextInt();
		long nowTab = 1;
		long kuso = 0;
		char[] arr = sc.next().toCharArray();
		for(char c : arr) {
			if(c=='+') {
				nowTab++;
				if(nowTab > limit) {
					kuso++;
					nowTab = 1;
				}
			} else {
				nowTab = Math.max(nowTab-1, 1);
			}
		}
		System.out.println(kuso);
	}
}