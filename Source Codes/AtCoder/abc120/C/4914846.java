import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();

		int count = 0;
		String inputStr[] = new String[input.length()];
		int currentIndex = 0;
		for(int i = 0; i < input.length(); i++) {
			inputStr[currentIndex]= input.substring(i,i+1);
			if(currentIndex!=0 && !inputStr[currentIndex].equals(inputStr[currentIndex-1])) {
				currentIndex--;
				count+=2;
			}else {
				currentIndex++;
			}
		}
		System.out.println(count);
		sc.close();
	}
}