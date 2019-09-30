import java.util.Scanner;

public class Main {

		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int M = sc.nextInt();
			int x = 0;
			if(1 <= M && M <= 23) {x = 24 + (24 - M);}
			System.out.println(x);
   }
	}