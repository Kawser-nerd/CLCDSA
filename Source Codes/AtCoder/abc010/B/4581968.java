import java.util.Scanner;


public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int count = 0;

			int f = sc.nextInt();
			for(int i = 0; i< f; i++) {
				int m = sc.nextInt();
				if(m==2) {
					count = count +1;
				}else if(m!=1){
					if(m%2==0) {
						if(m%3 ==0) {
							count = count + 3;
						}else {
							count = count +1;
						}
					}else if(m%5==0) {
						count = count +2;
					}
				}
			}
			System.out.println(count);
		}
}