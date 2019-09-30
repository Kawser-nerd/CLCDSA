import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		int a=0,b=0,c=0,d=0,e=0,f=0;
		for(int i=0;i<s.length();i++) {
			switch(s.charAt(i)) {
			case'A':
				a++;
				break;
			case'B':
				b++;
				break;
			case'C':
				c++;
				break;
			case'D':
				d++;
				break;
			case'E':
				e++;
				break;
			case'F':
				f++;
				break;
			}
		}
		System.out.println(a+" "+b+" "+c+" "+d+" "+e+" "+f);
	}
}