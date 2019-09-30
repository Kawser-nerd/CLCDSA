import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String str=scan.next();
		char a=str.charAt(0);
		int count=0;
		for(int i=1;i!=str.length();i++) {
			char b=str.charAt(i);
			if(a!=b) {
				count++;
			}
			a=str.charAt(i);
		}
		System.out.println(count);
	}
}