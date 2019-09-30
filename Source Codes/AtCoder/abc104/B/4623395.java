import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		boolean b1,b2=false,b3=true;
		b1=(s.charAt(0)=='A');
		for(int i=1;i<s.length();i++) {
			char c=s.charAt(i);
			if(i!=1&&i!=s.length()-1&&c=='C') {
				if(!b2) {
					b2=true;
				}else {
					b1=false;
				}
			}else if(Character.isUpperCase(c)) {
				b3=false;
			}
		}
		if(b1&&b2&&b3) {
			System.out.println("AC");
		}else {
			System.out.println("WA");
		}
	}
}