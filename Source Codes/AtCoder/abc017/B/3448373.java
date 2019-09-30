import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String X = sc.next();
		sc.close();
		
		boolean flag = true;
		for(int i = 0;i < X.length();++i) {
			switch(X.charAt(i)) {
			case 'o':
			case 'k':
			case 'u':
				continue;
			}
			if(i+2 > X.length()) {
				flag = false;
				break;
			}
			if(X.substring(i, i+2).equals("ch")) {
				i++;
				continue;
			}
			flag = false;
		}
		
		if(flag)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}