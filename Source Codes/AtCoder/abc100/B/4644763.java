import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int n = sc.nextInt();
		int ans = 1;

		for(int i = 0; i < d; i++) {
			ans = ans * 100;
		}
		if(n == 100) {
			ans = ans * n + ans;
		}else  {
			ans = ans * n;
		}

		System.out.println(ans);

		sc.close();
	}

}