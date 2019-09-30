import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int c0 = 0, c1 = 0;
		String str = null;
		Scanner scan = new Scanner(System.in);
		str = scan.nextLine();
		
		for(int i = 0;i < str.length();i++){
			String s = str.substring(i, i+1);
			if(s.equals("0"))c0++;
			else c1++;
		}
		
		scan.close();
		if(c0 < c1)System.out.println(c0*2);
		else System.out.println(c1*2);
		
	}
	
}