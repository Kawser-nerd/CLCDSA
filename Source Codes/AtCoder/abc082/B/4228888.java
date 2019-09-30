import java.util.Arrays;
import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	String a=scan.next();
	String b=scan.next();
	char c[]=new char[a.length()];
	char d[]=new char[b.length()];
	char e[]=new char[b.length()];
	for(int i=0;i!=a.length();i++) {
		c[i]=a.charAt(i);
	}
	for(int i=0;i!=b.length();i++) {
		d[i]=b.charAt(i);
	}
	Arrays.sort(c);
	Arrays.sort(d);
	for(int i=0;i!=b.length();i++) {
		e[i]=d[b.length()-i-1];
	}
	String A="";
	String B="";
	for(int i=0;i!=a.length();i++) {
		A=A+c[i];
	}
	for(int i=0;i!=b.length();i++) {
		B=B+e[i];
	}
	
	System.out.println(A.compareTo(B)<=-1?"Yes":"No");
}
}