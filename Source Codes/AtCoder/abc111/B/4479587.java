import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		String n=sc.nextLine();
		int ans=Integer.parseInt(n.substring(0,1));
		if(n.charAt(0)<n.charAt(1)||n.charAt(0)<n.charAt(2)) {
			ans++;
		}
		System.out.println(ans*100+ans*10+ans);
	}
}