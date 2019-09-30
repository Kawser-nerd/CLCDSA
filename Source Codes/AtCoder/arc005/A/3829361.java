import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		String s="";
		int c=00;
		for(int i=0; i<a; i++) {
			s=sc.next();
			if(s.charAt(s.length()-1)=='.') {
				s=s.substring(0,s.length()-1);
			}
			if(s.equals("TAKAHASHIKUN")) {
				c++;
			}
			else if(s.equals("Takahashikun")) {
				c++;
			}
			else if(s.equals("takahashikun")) {
				c++;
			}
		}
		System.out.println(c);
	}
}