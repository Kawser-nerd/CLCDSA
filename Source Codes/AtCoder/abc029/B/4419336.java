import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String[] words = new String[12];
		//12???????????
		for(int i=0; i<12; i++) {
			String word = scan.next();
			words[i] = word;
		}
		//'r'??????????
		int count = 0;
		for(int i=0; i<12; i++) {
			if(words[i].contains("r")) {
				count++;
			}
		}
		System.out.println(count);

	}

}