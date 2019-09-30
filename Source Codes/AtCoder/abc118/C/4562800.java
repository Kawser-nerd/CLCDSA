import java.util.*;
public class Main {
	
	public static int gcd(int a, int b) {
		if(b == 0)
			return a;
		else
			return gcd(b, a % b);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int answer = gcd(sc.nextInt(), sc.nextInt());
		for(int i = 2; i < n; i++) {
			answer = gcd(answer, sc.nextInt());
		}
		System.out.println(answer);
	}

}