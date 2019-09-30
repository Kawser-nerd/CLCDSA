import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		int n=s.nextInt();

		if(n==1) {
			System.out.println("Not Prime");
			return;
		}

		for(int i=2;i*i<=n;i++) {
			if(n%i==0) {
				if(n%2==0||n%5==0) {
					System.out.println("Not Prime");
					return;
				}
				int sum=0;
				while (n!=0) {
					sum+=n%10;
					n/=10;
				}
				System.out.println(sum%3==0?"Not Prime":"Prime");
				return;
			}
		}
		System.out.println("Prime");
	}
}