import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		int n = scanner.nextInt();
		int N = scanner.nextInt();
		int rest = 0;
		int product = 0;
		int ans = N;
		while(N >= m){
			product = (N/m)*n;
			rest = N % m;
			N = product + rest;
			ans += product;
		}
		System.out.println(ans);
	}
}