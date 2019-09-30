import java.util.*;
 
public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		HashMap<String, Integer> set = new HashMap<>();
		set.put("Sunday", 0);
		set.put("Monday", 5);
		set.put("Tuesday", 4);
		set.put("Wednesday", 3);
		set.put("Thursday", 2);
		set.put("Friday", 1);
		set.put("Saturday", 0);
		String day = sc.next();
		System.out.println(set.get(day));
	}
}