import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int[] a = new int[N];
		int[] b = new int[N];
		for(int i = 0; i < N; i++){
			a[i] = scanner.nextInt();
			b[i] = scanner.nextInt();
		}
		int ans = 0;
		for(int i = 0; i < N; i++){
			ans += a[i] * b[i];
		}
		ans += ans/20;
		System.out.println(ans);
	}
}