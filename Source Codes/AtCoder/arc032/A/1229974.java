import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int n=s.nextInt();

		if(n==1) {
			System.out.println("BOWWOW");
			return;
		}

		n=n*(n+1)/2;
		for(int i=2;i<n;i++) {
			if(n%i==0) {
				System.out.println("BOWWOW");
				return;
			}
		}
		System.out.println("WANWAN");
	}
}