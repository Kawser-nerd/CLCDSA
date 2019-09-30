import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int g = sc.nextInt();
		String N = sc.next();
		
		int[] map = new int[4];
		for (int i = 0; i < N.length(); i++) {
			map[Character.getNumericValue(N.charAt(i))-1]++;
		}
		
		int max = 0;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < map.length; i++) {
			max = Math.max(max, map[i]);
			min = Math.min(min, map[i]);
		}
		
		System.out.println(max + " " + min);
	}
	
	
}