import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		int x=0;int y=0;
		int uk=0;
		for(int i=0;i<s.length();i++) {
			switch (s.substring(i,i+1)) {
				case "R":x++;break;
				case "L":x--;break;
				case "D":y--;break;
				case "U":y++;break;
				case "?":uk++;break;
			}
		}
		int ans=Math.abs(x)+Math.abs(y);
		int t=sc.nextInt();
		if(t==1)System.out.println(ans+uk);
		else {
			if(ans>=uk)System.out.println(ans-uk);
			else System.out.println((uk-ans)%2);
		}
	}
	}