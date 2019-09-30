import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		int[] m = new int[N];
		for (int i = 0; i < N; i++) {
			m[i] = sc.nextInt();
		}
		
		int cnt = 0;
		int sum = 0;
		int min = X;
		for (int i = 0; i < N; i++) {
			sum += m[i];
			cnt++;
			if (m[i] < min)
				min = m[i];
		}
		
		X -= sum;
		while(X >= min) {
			X -= min;
			cnt++;
		}
		
		System.out.println(cnt);
		
		sc.close();

	}

}