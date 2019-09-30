//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int[] ar = {1,2,1,3,1,3,1,1,3,1,3,1};
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		System.out.println(ar[x-1]==ar[y-1]?"Yes":"No");
	}
}