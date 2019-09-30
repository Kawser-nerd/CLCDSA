import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		HashSet<Integer> set = new HashSet<>();
		for (int i=0; i<n; i++) {
			int temp = sc.nextInt();
			if (set.contains(temp)) {
				set.remove(temp);
			}
			else {
				set.add(temp);
			}
		}
		System.out.println(set.size());
		
	}
}