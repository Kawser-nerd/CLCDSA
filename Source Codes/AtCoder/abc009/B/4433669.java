import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main (String args[]) {
		int n = sc.nextInt();
		TreeSet<Integer> set = new TreeSet<>();
		for (int i=0; i<n; i++) set.add(sc.nextInt());
		
		set.pollLast();
		System.out.println(set.pollLast());
		
		
	}
}