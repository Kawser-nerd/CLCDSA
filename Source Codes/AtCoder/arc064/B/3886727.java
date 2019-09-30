import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		
		if(s.charAt(0)==s.charAt(s.length()-1)){
			int guki=s.length()-1;
			System.out.println(guki%2==0?"Second":"First");
		}else{
			int guki=s.length();
			System.out.println(guki%2==0?"Second":"First");
		}
	}
}