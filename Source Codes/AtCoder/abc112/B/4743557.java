import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		int t = Integer.parseInt(sc.next());
		
		Map<Integer, Integer> map = new HashMap<Integer,Integer>();
		
		for(int i = 0; i < n; i++) {
			int c = Integer.parseInt(sc.next());
			int time = Integer.parseInt(sc.next());
			
			if(time <= t) {
				map.put(c, time);
			}
		}
		
		int min = Integer.MAX_VALUE;
		
		for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
			min = Math.min(entry.getKey(), min);
		}
		
		System.out.println(min == Integer.MAX_VALUE ? "TLE" : min);
		
	}
}