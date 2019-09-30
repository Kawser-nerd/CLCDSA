import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		for(int i=0;i<s.length()-1;i++) {
			if(s.charAt(i)==s.charAt(i+1)) {
				System.out.println((i+1)+" "+(i+2));
				return;
			}
			try {
				if(s.charAt(i)==s.charAt(i+2)) {
					System.out.println((i+1)+" "+(i+3));
					return;
				}
			}catch(Exception e) {
				System.out.println(-1+" "+-1);
				return;
			}
		}
	}
}