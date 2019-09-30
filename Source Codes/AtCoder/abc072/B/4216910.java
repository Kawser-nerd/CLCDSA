import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	String a=scan.next();
	StringBuilder ans=new StringBuilder();
	
	for(int i=0;i!=a.length();i++) {
		if(i%2==0) {
			ans.append(a.charAt(i));
		}
	}
	System.out.println(ans);
	scan.close();
}
}