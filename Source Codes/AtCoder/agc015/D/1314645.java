import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner io = new Scanner(System.in);
		long A = io.nextLong();
		long B = io.nextLong();
		
		System.out.println(orNum(A,B));
		
		
	}
	
	public static long orNum(long A,long B){

		long q = 1L << 59;
		
		for(;q>0;q=q>>1){
			if((A&q)==0 && (B&q)==0)
				continue;
			if((A&q)!=0 && (B&q)!=0){
				A -= q; B -= q;
				continue;
			}
			if((A&q)==0 && (B&q)!=0){
				break;
			}
			if(((A&q)!=0 && (B&q)==0)){
				return 0;
			}
		}

		if(A==B){
			return 1;
		}
		
		long ans = q-A;
		ans = ans *2+1;
		B -= q;
		ans += Math.min(A-1,orNum(1,B));
		return ans;
	}
}