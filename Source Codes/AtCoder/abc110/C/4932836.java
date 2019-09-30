import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		String t=sc.next();
		char[]c=new char[]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		int cidx=0;
		for(int i=0;i<s.length();i++) {
			char sca=s.charAt(i);
			if(Character.isLowerCase(sca)) {
				s=s.replace(sca,c[cidx++]);
			}
		}
		cidx=0;
		for(int i=0;i<t.length();i++) {
			char sca=t.charAt(i);
			if(Character.isLowerCase(sca)) {
				t=t.replace(sca,c[cidx++]);
			}
		}
		System.out.println(s.equals(t)?"Yes":"No");
	}
}