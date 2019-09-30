import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int count = 0;
		
		for(int i = 105 ; i <= n ; i += 2) {
			int y = 0;
			for(int j = 1 ; j <= n ; j++) {
				if(i % j == 0) {
					y++;
				}
			}
			
			if(y == 8) {
				count++;
			}
		}
		
		System.out.println(count);
		
	}

}