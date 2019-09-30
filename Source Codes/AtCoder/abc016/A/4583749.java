import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			
			int m = sc.nextInt();
			int d = sc.nextInt();
			
			if(m>=d) {
			if(m%d==0) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
			}else {
				System.out.println("NO");
			}
			
			
		}
		
}