import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int x = sc.nextInt();
		
		long ans = 0;
		int last = 0;
		for(int i=0; i<N; i++) {
			int a = sc.nextInt();
			int eat = Math.max(0, last+a-x);
			ans += eat;
			last = a-eat;
		}
		
		System.out.println(ans);
		sc.close();
	}
}