import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner io = new Scanner(System.in);
		String S = io.next();
		long ans = 0;
		for(int i=0;i<S.length();i++){
			if(S.charAt(i)=='U'){
				ans += ((S.length()-1)-i)+i*2;
			}else{
				ans += ((S.length()-1)-i)*2+i;
			}
		}
		System.out.println(ans);
	}	
}