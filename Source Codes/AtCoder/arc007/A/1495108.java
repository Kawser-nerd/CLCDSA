import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		String brokenButton = br.readLine();
		String[] stringArray = br.readLine().split("");
		for(String letter : stringArray) {
			if(!letter.equals(brokenButton)) {
				System.out.print(letter);
			}
		}
		System.out.println();
	}
}