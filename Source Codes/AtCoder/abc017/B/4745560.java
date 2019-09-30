import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		String ans="YES";
		for(int i=0;i<s.length();) {
			if(s.substring(i,i+1).equals("c")&&s.substring(i+1,i+2).equals("h")) {
			i+=2;
		}else if(s.substring(i,i+1).equals("o")) {
			i++;
		}else if(s.substring(i,i+1).equals("k")) {
			i++;
		}
		else if(s.substring(i,i+1).equals("u")) {
			i++;
		}
		else{
			ans="NO";
			break;
		}
		}
		System.out.println(ans);
	}
}