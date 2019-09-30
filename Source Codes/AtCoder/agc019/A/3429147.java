import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	final static int ICE_TEA_COUNT = 4;
	final static double SHORT_TEA = 0.25;

	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader ( new InputStreamReader(System.in));
		String [] input = br.readLine().split(" ");
		String  input2 = br.readLine();
		long [] iceTeaList = new long[4];
		for(int i = 0;i<ICE_TEA_COUNT ;i++) {
			iceTeaList[i] = Integer.parseInt(input[i]);
		}

		int max = Integer.parseInt(input2);
		long [] resultTea = new long[4];
		int multiple = 2;
		long beforeResult = 1;
		boolean continueFlag = false;
		int point = 0;
		resultTea[0] = (long)( max / SHORT_TEA);
		for(int i = 0;i<ICE_TEA_COUNT-1 ;i++) {
			if(beforeResult == 0) {
				continueFlag = true;
			}else if(iceTeaList[i+point]*multiple > iceTeaList[i+1]) {
				resultTea[i+1] = resultTea[i+point]/multiple;
				resultTea[i+point] = resultTea[i+point]%multiple;
				continueFlag = false;
				point = 0;
				multiple = 2;
			}
			if(continueFlag) {
				point -= 1;
				multiple *=2;
				if(i+point >= 0) {
					beforeResult = (long)resultTea[i+point];
					i -= 1;
				}else {
					beforeResult = 1;
				}

				continue;
			}
			beforeResult = resultTea[i+1];
		}
		System.out.println(resultTea[0] * iceTeaList[0] + resultTea[1] *  iceTeaList[1] + resultTea[2] *  iceTeaList[2] + resultTea[3] * iceTeaList[3]);
	}
}