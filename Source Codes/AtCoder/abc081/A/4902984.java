import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] line = sc.nextLine().split("");
		sc.close();
		int cnt = 0;

		for(int i = 0; i< line.length; i++) {
			if(line[i].equals("1")) {
				cnt++;
			}
		}

		System.out.println(cnt);

	}

}