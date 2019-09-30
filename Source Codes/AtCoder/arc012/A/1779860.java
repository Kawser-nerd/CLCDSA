import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String day = sc.next();
		Map<String, Integer> map = new HashMap<>();
		map.put("Monday", 5); map.put("Tuesday", 4); map.put("Wednesday", 3);
		map.put("Thursday", 2); map.put("Friday", 1); map.put("Saturday", 0); map.put("Sunday", 0);
		for(String ans : map.keySet()) {
			if(day.equals(ans)) {
				System.out.println(map.get(ans));
			}
		}
	}
}