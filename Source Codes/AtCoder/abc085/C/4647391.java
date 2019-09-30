import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner( System.in );
		
		int N = sc.nextInt();
		int Y = sc.nextInt();
		boolean breakFlag = false;
		
		for ( int i = 0; i < N + 1; i++ ) {
			
			for ( int j = i; j < N + 1; j++ ) {
				int a = i;
				int b = j - i;
				int c = N - j;
				
				if ( 10000 * a + 5000 * b + 1000 * c == Y ) {
					System.out.println(a + " " + b + " " + c);
					breakFlag = true;
					break;
				}
			}
			
			if ( breakFlag ) {
				break;
			}
		}
		
		if (!breakFlag) {
			System.out.println("-1 -1 -1");
		}
		
		sc.close();

	}

}