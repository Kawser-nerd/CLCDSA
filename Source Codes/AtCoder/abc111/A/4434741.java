import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		String s1= sc.next();
		String s2= s1.replace("1","2");
		String s3=s2.replace("9","1");
		String s4=s3.replace("2", "9");
		System.out.println(Integer.parseInt(s4));
	}
}