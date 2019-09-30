import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {

		HashMap<String, Integer> map = new HashMap<>();

		// --- input ---
		int n = Integer.parseInt(in.readLine());
		for(int i=0; i < n; i++) {
			String key = in.readLine();
			if(map.containsKey(key)) {
				map.put(key, map.get(key) + 1);
			} else {
				map.put(key, 1);
			}
		}

		int m = Integer.parseInt(in.readLine());
		for(int i=0; i < m; i++) {
			String key = in.readLine();
			if(map.containsKey(key)) {
				map.put(key, map.get(key) - 1);
			} else {
				map.put(key, -1);
			}
		}
		in.close();

		int max = -1;
		for(int val : map.values()) {
			if(max < val) {
				max = val;
			}
		};

		// --- resolv ---
		System.out.println(max < 0 ? 0 : max);
	}
}