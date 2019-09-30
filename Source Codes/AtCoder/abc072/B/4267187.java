import java.util.Scanner;
class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		String str=sc.next();
		for(int i=0;i<str.length();i++) {
			if(i%2==0) {
				System.out.print(str.charAt(i));
			}
		}
		System.out.println();
	}
}