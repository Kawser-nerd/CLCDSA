import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		String a=scan.next();
		int A=0,B=0,C=0,D=0,E=0,F=0;
		for(int i=0;i!=a.length();i++) {
			char b=a.charAt(i);
			switch(b) {
			case'A':A++;break;
			case'B':B++;break;
			case'C':C++;break;
			case'D':D++;break;
			case'E':E++;break;
			case'F':F++;break;
			}
		}
		System.out.println(A+" "+B+" "+C+" "+D+" "+E+" "+F);
	}
}