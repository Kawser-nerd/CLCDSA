import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// get a integer
		int a = sc.nextInt();
		// get two integers separated with half-width break
		int b = sc.nextInt();
		int c = sc.nextInt();
		// get a string
		int cnt_5 = 0;
		int cnt_7 = 0;
				
		if(a == 5) {
			cnt_5++;
		} else if(a == 7) {
			cnt_7++;
		}
		
		if(b == 5) {
			cnt_5++;
		} else if(b == 7) {
			cnt_7++;
		}
		
		if(c == 5) {
			cnt_5++;
		} else if(c == 7) {
			cnt_7++;
		}
			
		if(cnt_5 == 2 && cnt_7 == 1) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
		
		
	}
}