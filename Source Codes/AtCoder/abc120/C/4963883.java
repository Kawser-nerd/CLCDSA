import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		String[]strArray = new String[s.length()];
		
		int zero=0;
		int one=0;
		
		for(int i=0;i<s.length(); i++) {
			strArray[i]=String.valueOf(s.charAt(i));
		}
		
		for(int i=0; i<s.length(); i++) {
			if(strArray[i].equals("0"))  zero++;			
			else 	one++;
		}
		if(zero<=one) System.out.println(zero*2);
		else System.out.println(one*2);
	}
}