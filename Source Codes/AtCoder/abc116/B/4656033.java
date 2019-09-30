import java.util.*;

public class Main {
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int s = sc.nextInt();
		
		HashMap<Integer, Boolean> record = new HashMap<Integer, Boolean>();
		record.put(s, true);
		int count = 1;
		while(true) {
			s = f(s);
			count++;
			if (record.containsKey(s)) {
				System.out.println(count);
				break;
			}
			record.put(s, true);
		}
	}
	
	public static int f(int n) {
		if (n%2 == 0) {
			return n/2;
		}
		return 3*n+1;
	}
}