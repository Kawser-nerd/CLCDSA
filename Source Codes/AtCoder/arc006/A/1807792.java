import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		String inputWinNumber = br.readLine();
		String bonusNumber = br.readLine();
		String inputChosenNumber = br.readLine();
		String[] winNumbers = inputWinNumber.split(" ");
		String[] chosenNumbers = inputChosenNumber.split(" ");
		int count = 0;
		int bonusFlag = 0;
		for (String chosenNumber : chosenNumbers) {
			for(String winNumber : winNumbers) {
				if(chosenNumber.equals(winNumber)) {
					count++;
				}
			}
			if(chosenNumber.equals(bonusNumber)) {
				bonusFlag = 1;
			}
		}
		int result=0;
		switch(count) {
		case 0:
		case 1:
		case 2:
			result=0;
			break;
		case 3:
			result=5;
			break;
		case 4:
			result=4;
			break;
		case 5:
			if(bonusFlag == 1) {
				result=2;
			}else {
				result=3;
			}
			break;
		case 6:
			result=1;
			break;
		}
		System.out.println(result);
	}
}