import java.util.*;
import static java.lang.System.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		HashMap<String,Integer> map = new HashMap<>();
		int n = sc.nextInt();
		String s;
		for (int i=0; i<n; i++) {
			s = sc.next();
			map.put(s,map.getOrDefault(s,0));
			map.put(s,map.get(s)+1);
		}
		int m = sc.nextInt();
		for (int i=0; i<m; i++) {
			s = sc.next();
			map.put(s,map.getOrDefault(s,0));
			map.put(s,map.get(s)-1);
		}
		int max = 0;
		for (Map.Entry<String,Integer> e : map.entrySet()) {
			max = Math.max(max,e.getValue());
		}
		out.println(max);
	}
}