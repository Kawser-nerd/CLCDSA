import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		for(int i=0;;i++) {
			if(i*i*i*i==a) {
				System.out.println(i);
				break;
			}
		}
	}
}