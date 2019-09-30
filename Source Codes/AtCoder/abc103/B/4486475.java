import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		StringBuffer str1=new StringBuffer(sc.nextLine());
		StringBuffer str2=new StringBuffer(sc.nextLine());		
		int len=str1.length();
		if(len!=str2.length()){
			System.out.println("No");
			return;
		}
		while(len-->0){
			StringBuffer sb=new StringBuffer();
			char c=str1.charAt(0);
			sb.append(str1.substring(1));
			sb.append(c);
			str1=sb;
			//System.out.println(str1);
			if(str1.toString().equals(str2.toString())){
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}
}