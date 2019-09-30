import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		String s = scan.next();
		char[] c = s.toCharArray();

		int max = 0;
		int x = 0;
		for(int i = 0; i < n; i++){
			if(c[i] == 'I'){
				x ++;
			}
			else {
				x --;
			}
			if(x > max){
				max = x;
			}
		}
		System.out.println(max);
	}
}