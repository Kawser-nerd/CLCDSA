import java.util.*;
 
public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String name = sc.next();
		String kit = sc.next();
		int[] names = new int[26];
		int[] kits = new int[26];
		for (char c : name.toCharArray()) {
			names[c - 'A']++;
		}
		for (char c : kit.toCharArray()) {
			kits[c - 'A']++;
		}
		int max = 1;
		for (int i = 0; i < 26; i++) {
			int x = names[i];
			int y = kits[i];
			if (x == 0) {
				continue;
			}
			if (y == 0) {
				System.out.println(-1);
				return;
			}
			if (x > y) {
				int v = (x + y - 1) / y;
				if (max < v) {
					max = v;
				}
			}
		}
		System.out.println(max);
	}
}