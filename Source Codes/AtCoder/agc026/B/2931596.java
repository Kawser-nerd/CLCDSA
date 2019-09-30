import java.util.*;

public class Main{

	public static void main(String[] args){
	
		Scanner scan = new Scanner(System.in);
		
		int allNum = scan.nextInt();
		
		long fStock = 0;
		long buy = 0;
		long aCheck = 0;
		long pStock = 0;
		
		for(int i=0; i < allNum; i++){
			
			fStock = scan.nextLong();
			buy = scan.nextLong();
			aCheck = scan.nextLong();
			pStock = scan.nextLong();
			
			if(check(fStock,buy,aCheck,pStock)) System.out.println("Yes");
			else System.out.println("No");
			
		}
		scan.close();
	
	}	
	
	private static boolean check(long fStock,long buy,long aCheck,long pStock){
		
		if(fStock < buy) return false;
		if(buy > pStock) return false;
		if(aCheck >= buy) return true;
		
		long ba = baCheck(buy,pStock);
		
		if(buy - ba + (fStock % ba) > aCheck) return false;
		else return true;
	}
	
	private static long baCheck(long buy,long pStock){
		long c = buy % pStock;
		if(c==0) return pStock;
		return baCheck(pStock,c);
	}

}