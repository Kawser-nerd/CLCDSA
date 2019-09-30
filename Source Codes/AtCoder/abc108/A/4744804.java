import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int nagasa = sc.nextInt();
		int count1 = 0;
		int count2 = 0;
		for(int i=0;i<nagasa;i++) {
			if(i%2 == 0) {
				count1++;
			}else {
				count2++;
			}
		}
		System.out.println(count1*count2);

	}
}