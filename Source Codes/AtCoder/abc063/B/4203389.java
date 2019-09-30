import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	String a=scan.next();
	for(int i=0;i!=a.length()+1;i++) {
		if(i==a.length()) {
			System.out.println("yes");
			return;
		}
		char ch=a.charAt(i);
		int count=0;
		for(int j=i;j!=a.length();j++) {
			char ch2=a.charAt(j);
			if(ch==ch2) {
				count++;
			}
		}
		if(count!=1) {
			System.out.println("no");
			return;
		}
	}
}
}