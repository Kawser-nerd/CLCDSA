import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();

		if(N % 500 == 0) 
			System.out.println("Yes");
		else {
			N = N % 500;
			if(N < A) 
				System.out.println("Yes");
			else
				System.out.println("No");
		}

		sc.close();
	}
}