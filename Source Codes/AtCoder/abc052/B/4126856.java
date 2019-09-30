import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		String S = scan.next();

		int x = 0;
		int max = 0;
		for (char s : S.toCharArray()) {
			switch (s) {
			case 'I':
				x++;
				if (max < x) {
					max = x;
				}
				break;
			case 'D':
				x--;
			}
		}
		System.out.println(max);
	}

}