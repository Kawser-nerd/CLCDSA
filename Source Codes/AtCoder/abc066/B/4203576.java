import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	String a=scan.next();
	for(int i=1;i!=a.length();i++) {
		String str=a.substring(0,a.length()-i);
		if(str.length()%2==1) {
			continue;
		}
		else {
			String str1=str.substring(0,str.length()/2);
			String str2=str.substring(str.length()/2,str.length());
			if(str1.equals(str2)) {
				System.out.println(str.length());
				return;
			}
		}
	}
}
}