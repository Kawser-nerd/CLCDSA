//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		HashSet<Integer> set = new HashSet<>();
		for (int i=0; i<3; i++) {
			set.add(sc.nextInt());
		}
		
		System.out.println(set.size());
		
	}
}