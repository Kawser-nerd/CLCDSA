import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
	int ans=0;
		for(int i=0;i<12;i++) {
		String s=sc.next();
		if(s.contains("r"))ans++;
		}
		System.out.println(ans);
	}
}