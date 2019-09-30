import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		int M = Integer.parseInt(sc.next());
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		long sum[] = new long[N + 1];
		int A[] = new int[N + 1];
		A[1] = Integer.parseInt(sc.next());
		sum[0] = 0;
		sum[1] = A[1];
		map.put((int)(sum[1] % M), 1);
		for(int i = 2; i <= N; i++) {
			A[i] = Integer.parseInt(sc.next());
			sum[i] = sum[i - 1] + A[i];
			int mod = (int)(sum[i] % M);
			if(map.containsKey(mod)){
				map.put(mod, map.get(mod) + 1);
			} else {
				map.put(mod, 1);
			}
		}
		
		long ans = 0;
		Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator();
		while(it.hasNext()) {
			Map.Entry<Integer, Integer> mapEntry = it.next();
			long temp = 0;
			if(mapEntry.getKey() == 0) {
				for(long i = mapEntry.getValue(); i > 0; i--) {
					temp += i;
				}
			} else {
				for(long i = mapEntry.getValue() - 1; i > 0; i--) {
					temp += i;
				}
			}	
			if(temp != 0 || mapEntry.getKey() == 0) {
				ans += temp;
			}
		}
		System.out.println(ans);
	}
}