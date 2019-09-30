import java.util.Scanner;


public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			
			String a = sc.next();
			
			String[]al = new String[] {"A","B","C","D","E"};
			
			for(int i=0; i <=4; i++) {
				if(a.equals(al[i])) {
					System.out.println(i + 1);
				}
			}
			
		}
}