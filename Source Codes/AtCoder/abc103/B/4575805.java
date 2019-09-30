//2019/3/14
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String S = sc.next();

		String T = sc.next();

		String SS = S+S;

		boolean flag = false;

		boolean ans = false;

		//??????
		for(int i=0;i<S.length();i++) {

			flag = false;

			for(int j=0;j<S.length();j++) {

				if(SS.charAt(i+j)!=T.charAt(j)) flag = true;
			}

			if(!flag) ans = true;
		}

		if(ans)System.out.println("Yes");

		else System.out.println("No");
	}

}