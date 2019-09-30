import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = (int)sc.nextInt();
		int a[] = new int[N];
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		
		int ans = 0;
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		for(int i = 0; i < N; i++) {
			while(a[i] % 2 == 0) {
				a[i] /= 2;
			}
			map.put(a[i], 1);
		}
		System.out.println(map.size());
	}
}