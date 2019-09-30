import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		String s = scan.next();
		char[] c = s.toCharArray();

		int start = 0;
		for(int i = 0; i < s.length(); i++){
			if(c[i] == 'A'){
				start = i;
				break;
			}
		}

		int end = 0;
		for(int i = s.length()-1; i > start; i--){
			if(c[i] == 'Z'){
				end = i;
				break;
			}
		}
		System.out.println(end - start +1);
	}
}