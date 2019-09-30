import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		String[]s=new String[2];
		s[0]=sc.next();
		s[1]=sc.next();
		char[]c=new char[]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		for(int j=0;j<2;j++) {
			int cidx=0;
			for(int i=0;i<s[j].length();i++) {
				char sca=s[j].charAt(i);
				if(Character.isLowerCase(sca)) {
					s[j]=s[j].replace(sca,c[cidx++]);
				}
			}
		}
		System.out.println(s[0].equals(s[1])?"Yes":"No");
	}
}