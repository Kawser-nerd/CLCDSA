import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		String[] setting = br.readLine().split(" ");
		int nameNum = Integer.parseInt(setting[0]);
		int kitLetterNum = Integer.parseInt(setting[1]);
		String[] nameArray = br.readLine().split("");
		String[] kitArray = br.readLine().split("");
		int count = 1;
		int nullNum = 0;
		while(true) {
			for(int i=0;i<kitLetterNum;i++) {
				for(int j=0;j<nameNum;j++) {
					if(nameArray[j] == null) {

					}else if(nameArray[j].equals(kitArray[i])) {
						nameArray[j] = null;
						nullNum++;
						break;
					}
				}
			}
			if(nullNum == nameNum) {
				break;
			}else if(count == 50000) {
				count = -1;
				break;
			}else {
				count++;
			}
		}
		System.out.println(count);
	}
}