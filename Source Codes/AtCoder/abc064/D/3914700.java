import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		String s = scanner.next();
		String ans = "";
		int min = Integer.MAX_VALUE;
		int count = 0;
		for(int i = 0; i < s.length(); i++){
			if(s.charAt(i) == '('){
				count++;
			}else if(s.charAt(i) == ')'){
				count--;
			}
			if(count < 0){
				min = Math.min(count, min);
			}
		}
			for(int i = 0; i < -min; i++){
				ans = "(" + ans;
			}
		ans += s;
		int count2= 0;
		for(int i = 0; i < ans.length(); i++){
			if(ans.charAt(i) == '('){
				count2 += 1;
			}else if(ans.charAt(i) == ')'){
				count2 -= 1;
			}
		}
		for(int i = 0; i < count2; i++){
			ans = ans + ")";
		}
		System.out.println(ans);
	}
}