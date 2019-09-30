import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int wantUpper = n;

		boolean isP = true;
		for(int i = 2; i <= Math.sqrt(wantUpper); i++) {
			if(n%i==0) {
				isP = false;
				break;
			}
		}
		if(n!=1 && isP) {
			System.out.println("Prime");
		} else {
			int a = n%10;
			if(n!=1&&a!=5&&n%3!=0&&a%2!=0) {
				System.out.println("Prime");
			} else {
				System.out.println("Not Prime");
			}
		}
	}
}