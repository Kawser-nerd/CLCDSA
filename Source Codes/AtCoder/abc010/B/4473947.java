import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int flower = scn.nextInt();
		int count = 0;
		for(int i=0; i<flower; i++) {
			int a = scn.nextInt();
				if(a%2==0) {
					if(a == 6) {
						count += 3;
					}else {
						count++;
					}
				}else if(a==5) {
					count += 2;
				}
		}
		System.out.println(count);
	}

}