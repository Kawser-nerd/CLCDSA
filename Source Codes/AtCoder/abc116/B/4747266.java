import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int [] aArray = new int [1000000];
		int s = sc.nextInt();
		aArray[1] = s;
		int i = 2;
		out: while(true) {
			if(aArray[i-1] % 2 == 0) aArray[i] = aArray[i-1] / 2;
			else aArray[i] = 3 * aArray[i-1] + 1;
			for(int k = 1; k < i; k++) {
				if(aArray[i] == aArray[k]) {
					System.out.println(i);
					break out;
				}
			}
			i++;
		}
		sc.close();
	}

}