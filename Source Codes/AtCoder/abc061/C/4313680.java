import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt(); long k = sc.nextLong();
		TreeMap<Integer, Long> map = new TreeMap<>();
		for (int i=0; i<n; i++) {
			int temp = sc.nextInt();
			int num  =sc.nextInt();
			map.put(temp, map.getOrDefault(temp,0L)+num);
		}
		
		for (Map.Entry<Integer, Long> e: map.entrySet()) {
			k -= e.getValue();
			if (k <= 0) {
				System.out.println(e.getKey()); return;
			}
		}
		
	}
}