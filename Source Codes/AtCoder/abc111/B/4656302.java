import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int ans=0;
		for(int i=N ; i<=999 ; i++) {
			if(check(i)) {
				ans = i;
				break;
			}
		}
		System.out.println(ans);
		sc.close();
	}
	static boolean check(int n) {
		int one = n%10; n/=10;
		int two = n%10; n/=10;
		int thr = n%10;
		if( (one==two) && (two==thr) ) {
			return true;
		}
		return false;
	}

}