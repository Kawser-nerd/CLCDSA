import java.util.*;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		String s=sc.nextLine();
		int min=1000,sa;
		for(int i=0;i<s.length()-2;i++) {
			sa=Math.abs(753-Integer.parseInt(s.substring(i,i+3)));
			if(min>sa) {
				min=sa;
			}
		}
		System.out.println(min);
	}
}