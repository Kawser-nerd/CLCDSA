//2019/3/14
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String S = sc.next();

		boolean flag = false;

		//??????????
		if(S.charAt(0) != 'A') {

			flag = true;

		}else {

			int C = 0;

			for(int i=2;i<=S.length()-2;i++) {

				if(S.charAt(i) == 'C') C++;

			}

			if(C!=1) flag = true;

			char a = 0;

			for(int i=0;i<S.length();i++) {

				a = S.charAt(i);

				if(!(a=='A' || a=='C' || ((int)a>=97) && (int)a<=122)) flag = true;
			}
		}

		if(flag) System.out.println("WA");

		else System.out.println("AC");
	}

}