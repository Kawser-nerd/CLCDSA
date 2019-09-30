import java.util.*;

public class Main{    
    
	public static void main(String[] args) {
		
            Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		String S = in.next();
		
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		String[] s = new String[N - K + 1];
		int[] arr = new int[26];
		for (int i = 0; i <= N - K; i++) {
			if (i == 0) {
				for (int j = 0; j <= N; j++) {
					arr[S.charAt(i) - 'a']++;
				}
			} else {
				arr[S.charAt(i - 1) - 'a']--;
				arr[S.charAt(i + K - 1) - 'a']++;
			}
			s[i] = Arrays.toString(arr);
			if (map.containsKey(s[i])) {
				map.put(s[i], Math.max(map.get(s[i]), i));
			} else {
				map.put(s[i], i);
			}
		}
		
		for (int i = 0; i <= N - K; i++) {
			if (map.get(s[i]) - i >= K) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
                
	}               
}