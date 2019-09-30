import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = n;
		boolean judge = false;
		for(int i = 0; m >= 4; i++) {
			m = n - (4 * i);
			if(m % 7 == 0) {
				judge = true;
				break;
			}
		}
		if(judge) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		sc.close();
	}

}