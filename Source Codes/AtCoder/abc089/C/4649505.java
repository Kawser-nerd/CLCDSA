import java.util.*;

public class Main {

	static long Examine(long countM,long countA,long countR,long countC,long countH) {
		long count = 0;
		count += countM * countA * countR;
		count += countM * countA * countC;
		count += countM * countA * countH;
		
		count += countM * countR * countC;
		count += countM * countR * countH;
		
		count += countM * countC * countH;
		
		count += countA * countR * countC;
		count += countA * countR * countH;
		
		count += countA * countC * countH;
		
		count += countR * countC * countH;

		return count;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String[] names = new String[N];
		long countM = 0;
		long countA = 0;
		long countR = 0;
		long countC = 0;
		long countH = 0;
		String[] I = new String[N];
		for(int i = 0;i < N;i++) {
			names[i] = sc.next();
			I[i] = names[i].substring(0,1);
		}
		for(int k = 0;k < N;k++) {
			if(I[k].equals("M")) countM++;
			else if(I[k].equals("A")) countA++;
			else if(I[k].equals("R")) countR++;
			else if(I[k].equals("C")) countC++;
			else if(I[k].equals("H")) countH++;
		}
		System.out.println(Examine(countM,countA,countR,countC,countH));
		sc.close();
	}

}