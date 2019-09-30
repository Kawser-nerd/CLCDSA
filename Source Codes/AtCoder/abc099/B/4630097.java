import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m=sc.nextInt();
		int d=m-n;
		int ans=0;
		for(int i=1;i<=d;i++) {
			ans+=i;
		}
		System.out.println(ans-m);
	}
}