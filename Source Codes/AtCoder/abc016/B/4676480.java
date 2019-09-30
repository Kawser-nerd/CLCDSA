import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int l=sc.nextInt();
		int state=0;
		if(n+m==l)state+=1;
		if(n-m==l)state+=2;
		String ans="!";
		switch(state){
		case 0:break;
			case 1: ans="+";break;
			case 2: ans="-";break;
			case 3: ans="?";break;
		}
		System.out.println(ans);
	}
}