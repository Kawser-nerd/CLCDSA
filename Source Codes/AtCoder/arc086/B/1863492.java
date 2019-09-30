import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		String[] tmpArray = br.readLine().split(" ");
		
		int input[] = new int[n];
		
		for(int i = 0; i < n; i++){
			input[i] = Integer.parseInt(tmpArray[i]);
		}
		
		int times = 0;
		
		ArrayList<Operation> op = new ArrayList<Operation>();

		boolean allPositive = true;
		boolean allNegative = true;
		for(int i = 0; i < n; i++){
			if(input[i] < 0){
				allPositive = false;
			}
			else if(input[i] > 0){
				allNegative = false;
			}
		}
		
		if(allPositive){
			times = calcArray(input, op, true);
		}
		else if(allNegative){
			times = calcArray(input, op, false);
		}
		else {
			//??????????????????????
			int maxI = 0;
			int minI = 0;
			
			for(int i = 1; i < n; i++){
				if(input[i] > input[maxI]){
					maxI = i;
				}
				if(input[i] < input[minI]){
					minI = i;
				}
			}
			
			int fixI = 0;
			if(input[maxI] >= -input[minI]){
				fixI = maxI;
			}
			else {
				fixI = minI;
			}
			
//			int tmpTimes = 0;
			for(int i = 0; i < n; i++){
				if(i == fixI){
					continue;
				}
				input[i] += input[fixI];
				op.add(new Operation(fixI, i));
			}
			
			if(input[0] >= 0){
				calcArray(input, op, true);
			}
			else {
				calcArray(input, op, false);
			}
		}
		
//		for(int i = 1; i < n; i++){
//			if(input[i] >= input[i - 1]){
//				continue;
//			}
//			
//			//i?????
//		}
		
		System.out.println(op.size());
		for(int i = 0; i < op.size(); i++){
			System.out.println(op.get(i).toString());
		}
	}
	
	static int calcArray(int[] array, ArrayList<Operation> op, boolean forward){
		int n = array.length;
		int times = 0;
		if(forward){
			for(int i = 1; i < n; i++){
				array[i] += array[i-1];
				op.add(new Operation(i-1, i));
				times++;
			}
		}
		else {
			for(int i = n - 2; i >= 0; i--){
				array[i] += array[i + 1];
				op.add(new Operation(i+1, i));
				times++;
			}
		}
		
		return times;
	}

}

class Operation {
	int x;
	int y;
	
	public Operation (int x, int y){
		this.x = x + 1;
		this.y = y + 1;
	}
	
	public String toString(){
		return x+" "+y;
	}
}