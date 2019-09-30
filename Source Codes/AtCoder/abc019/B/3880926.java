import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String str=scan.next();
		String ans="";
		int j=1;
		for(int i=0;i!=str.length()-1;i++) {
			if(str.charAt(i)==str.charAt(i+1)) {
			j++;
			}
			else {ans=ans+str.charAt(i)+j;j=1;}
			if(i==str.length()-2) {ans=ans+str.charAt(i+1)+j;}
		}
		System.out.println(ans);
}
}