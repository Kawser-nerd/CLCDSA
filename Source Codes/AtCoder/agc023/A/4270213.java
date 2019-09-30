import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		long[] ar = new long[n+1];
		ar[0] = 0;
		HashMap<Long, Integer> map = new HashMap<>();
		map.put(0L,1);
		for (int i=1; i<n+1; i++) {
			ar[i] = sc.nextInt() + ar[i-1];
			map.put(ar[i], map.getOrDefault(ar[i],0)+1);
		}
		
		long ans = 0;
		for (Map.Entry<Long, Integer> e: map.entrySet()) {
			long temp = e.getValue();
			if (temp >= 2) {
//				System.out.println(e.getKey()+":"+e.getValue());
				ans += temp*(temp-1)/(long)2;
			}
		}
		
		System.out.println(ans);
		
//		for (int i=0; i<n+1; i++) System.out.println(ar[i]);
		
		
	}
}