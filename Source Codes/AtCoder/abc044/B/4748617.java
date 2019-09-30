import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		String str = scan.next();
		char[] c = str.toCharArray();

		for(int i = 0; i < c.length; i++){
			int count = 0;
			for(int j = 0; j < c.length; j++){
				if(c[i] == c[j]){
					count ++;
				}
			}
			if(count % 2 != 0){						
				System.out.println("No");
				System.exit(0);
			}
		}
		System.out.println("Yes");
	}
}