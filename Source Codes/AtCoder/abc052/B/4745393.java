import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		s=sc.next();
		int max=0;
		int sum=0;
		for(int i=0;i<s.length();i++) {
			if(s.substring(i,i+1).equals("I"))sum++;
			if(s.substring(i,i+1).equals("D"))sum--;
			max=Math.max(max, sum);
		}
		System.out.println(max);
	}
}