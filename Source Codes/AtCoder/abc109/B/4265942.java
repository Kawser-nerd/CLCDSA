import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		HashSet<String> set = new HashSet<>();
		String[] ar = new String[n];
		for (int i=0; i<n; i++) {
			ar[i] = sc.next();
			set.add(ar[i]);
		}
		
		if (set.size() < n) {
			System.out.println("No"); return;
		}
		
		boolean F = true;
		for (int i=0; i<n-1; i++) {
			if (ar[i].charAt(ar[i].length()-1) != ar[i+1].charAt(0)) {
				F = false; break;
			}
		}
		
		System.out.println(F?"Yes":"No");
		
	}
}