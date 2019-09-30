import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	String str1=scan.next();
	String str2=scan.next();
	int len=str1.length()<str2.length()?str1.length():str2.length();
	int lon=0;
	for(int i=0;i<len;i++) {
		if(str1.substring(i,str1.length()).equals(str2.substring(0,str2.length()-i))){
			lon=len-i;
			break;
		}
	}
	System.out.println(str1.length()+str2.length()-lon);
	}
}