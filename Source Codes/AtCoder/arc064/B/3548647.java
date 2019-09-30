import java.util.Scanner;

public class Main{
	
	public static void main(String args[])throws Exception{
		
		Scanner sc= new Scanner(System.in);
		String s = sc.next();
		int L = s.length();
		int same = 0;
		if(s.charAt(0) == s.charAt(L-1)){
			same = 1;
		}
		if((L+same)%2==0){
			System.out.println("Second");
		}else{
			System.out.println("First");
		}

	}
}