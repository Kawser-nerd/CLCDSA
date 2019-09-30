import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

	
public class Main{
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String N = sc.next();
		Long n = Long.parseLong(N);
		int s = N.length();
		String T = N.substring(0,1);
		Boolean ni = true;
		Boolean nu = true;
		for(int i=0;i<s;i++){
			if(N.charAt(i)!='9'){
				
				ni=false;
			}
			if(i>0&&N.charAt(i)!='9'){
				
				nu=false;
			}
		}

		if(ni){
			System.out.println(s*9);
		}else if(nu){
			System.out.println(9*(s-1) + Integer.parseInt(T));
		}else{
			System.out.println(9*(s-1) + Integer.parseInt(T)-1);
		}
		
	}
	
}