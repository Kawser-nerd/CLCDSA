import java.util.Scanner;
 
public class Main {
 
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			String S = sc.next();
			int c = 0;
			for(int i = 0; i < 3; i++) {
			if(S.charAt(i) == 'o') {
			c++;}}
			System.out.println(700 + 100 * c);
			}}