import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			
			String a = sc.next();
			String b = sc.next();
			
			int aa = a.length();
			int bb = b.length();
			
			if(aa>bb) {
				System.out.println(a);
			}else {
				System.out.println(b);
			}
			
		}
		
				  
}