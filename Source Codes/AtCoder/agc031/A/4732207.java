import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		sc.close();
		String abc = "qwertyuiopasdfghjklzxcvbnm";
		Map<String, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			if (map.containsKey(String.valueOf(s.charAt(i)))) {
				map.put(String.valueOf(s.charAt(i)), map.get(String.valueOf(s.charAt(i))) + 1);
			} else {
				map.put(String.valueOf(s.charAt(i)), 1);
			}
		}
		long ans = 1;
		long mod = 1000000007;
		for (int i = 0; i < 26; i++) {
			long get = 1;
			if (map.containsKey(String.valueOf(abc.charAt(i)))) {
				get += (long) map.get(String.valueOf(abc.charAt(i)));
			}
			ans *= get;
			ans %= mod;
		}
		ans--;
		System.out.println(ans);
	}
}