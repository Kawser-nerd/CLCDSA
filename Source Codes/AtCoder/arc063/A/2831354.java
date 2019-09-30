import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		char[] map = S.toCharArray();
		int ans = 0;
		char pre = map[0];
		for(int i = 1; i < map.length; i++) {
			if (pre != map[i]) {
				ans++;
				pre = map[i];
			}
		}
		
		System.out.println(ans);
	}

}