import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String [] sArray = s.split("");
		String num = "";
		int [] numArray = new int [sArray.length - 2];
		int mindif = Integer.MAX_VALUE;
		for(int i = 0; i < sArray.length - 2; i++) {
			num = sArray[i] + sArray[i+1] + sArray[i+2];
			numArray[i] = Integer.parseInt(num);
			
			int dif = 0;
			if(numArray[i] <= 753) dif = 753 - numArray[i];
			else dif = numArray[i] - 753;
			
			if(dif <= mindif) mindif = dif;
		}
		System.out.println(mindif);
		sc.close();
	}

}