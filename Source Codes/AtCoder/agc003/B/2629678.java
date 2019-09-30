import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {
	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		br.readLine();
		long result = 0;
		int card1 = Integer.parseInt(br.readLine());
		while(br.ready()) {
			int card2 = Integer.parseInt(br.readLine());
			if(card1>0 && card2>0 && card1%2 !=0) {
				card2 -= 1;
				result += 1;
			}
			result += card1/2;
			card1 = card2;
		}
		result += card1/2;
		System.out.println(result);
	}
}