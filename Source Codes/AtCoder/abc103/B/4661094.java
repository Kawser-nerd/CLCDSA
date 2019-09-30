import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		StringBuilder s,t;
		s= new StringBuilder(sc.next());
		t=new StringBuilder(sc.next());
		boolean flag=false;
		for(int i=0;i<s.length();i++) {
			s=new StringBuilder(Rotate(s));
			if(t.toString().equals(s.toString())) {
				flag=true;
				break;
			}
		}
		if(flag==true)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
	
	public static StringBuilder Rotate(StringBuilder str) {
		int len=str.length();
		char t=str.charAt(0);
		for(int i=0;i<len-1;i++) {
			str.setCharAt(i,str.charAt(i+1));			
		}
		str.setCharAt(len-1,t);
		return str;
	}
}