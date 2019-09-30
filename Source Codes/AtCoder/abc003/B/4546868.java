import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String l1 = sc.next();
		String l2 = sc.next();
		char temp1;
		char temp2;
		for (int i = 0; i < l1.length(); i++) {
			temp1=l1.charAt(i);
			temp2=l2.charAt(i);
			if (temp1 != temp2) {
				if(temp1=='@'&&(temp2=='a'||temp2=='t'||temp2=='c'||temp2=='o'||temp2=='d'||temp2=='e'||temp2=='r')) {
				}else if(temp2=='@'&&(temp1=='a'||temp1=='t'||temp1=='c'||temp1=='o'||temp1=='d'||temp1=='e'||temp1=='r')) {
				}else {
					System.out.println("You will lose");
					return;
				}
			}
		}
		System.out.println("You can win");
	}
}