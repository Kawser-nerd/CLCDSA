import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		
		if(A==B) {
			System.out.println(1);
		} else {
			int abi = 62;
			for(; abi>=0; abi--)
				if(((A^B)&(1l<<abi))!=0)
					break;
			long mask = (1l<<abi)-1;
			long ans = mask - (A&mask) + 1;
			
			int bi = abi-1;
			for(; bi>=0; bi--)
				if(((1l<<bi)&B)!=0)
					break;
			long temp = 1l<<(bi+1);
			ans += temp + (1l<<abi) - Math.max(temp, A&mask);
			
			System.out.println(ans);
		}
		
		sc.close();
	}
}