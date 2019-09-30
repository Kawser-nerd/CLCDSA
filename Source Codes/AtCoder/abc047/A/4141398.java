//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int[] ar = new int[3];
		for (int i=0; i<3; i++) ar[i] = sc.nextInt();
		Arrays.sort(ar);
		
		System.out.println(ar[0]+ar[1]==ar[2]?"Yes":"No");
		
	}
}