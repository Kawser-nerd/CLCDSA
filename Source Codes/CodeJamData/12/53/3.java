import java.util.*;
import java.math.*;

public class C{

	BigInteger func3(BigInteger low, BigInteger high, BigInteger constant, BigInteger slant, BigInteger xsum){ // System.out.println(low + " " + high + " " + constant + " " + slant);
		BigInteger minK = (xsum.add(high).subtract(BigInteger.ONE)).divide(high);
		BigInteger maxK = xsum;
		if(!low.equals(BigInteger.ZERO)) maxK = xsum.divide(low);
		if(maxK.compareTo(minK) < 0) return BigInteger.valueOf(1l<<60);
		
		BigInteger K = maxK;
		if(constant.compareTo(BigInteger.ZERO) > 0) K = minK;
		
		return slant.multiply(xsum).add(constant.multiply(K));
	}

	BigInteger func2(BigInteger C, int N, BigInteger[] price, BigInteger[] day, BigInteger xsum){ // xsum -> min ysum
		BigInteger low = BigInteger.ZERO;
		BigInteger init = C;
		BigInteger ans = BigInteger.valueOf(1l<<60);
		
		while(true){
			int next = -1;
			int i;
			for(i=0;i<N;i++) if(day[i].compareTo(low) > 0){
				if(next == -1 || price[i].compareTo(price[next]) < 0){
					next = i;
				}
			}
			if(next == -1) break;
			
		//	System.out.println(init);
			BigInteger tmp = func3(low, day[next], init.subtract(price[next].multiply(low)), price[next], xsum);
			if(tmp.compareTo(ans) < 0) ans = tmp;
			init = init.add((day[next].subtract(low)).multiply(price[next]));
			low = day[next];
		}
		
		return ans;
	}

	BigInteger func(BigInteger M, BigInteger C, int N, BigInteger[] price, BigInteger[] day){
		BigInteger low = BigInteger.ZERO; BigInteger high = BigInteger.valueOf(1l<<60);
		
		while(!high.subtract(low).equals(BigInteger.ONE)){
			BigInteger mid = (high.add(low)).divide(BigInteger.valueOf(2));
			BigInteger miny = func2(C, N, price, day, mid);
			if(miny.compareTo(M) <= 0) low = mid; else high = mid;
		}
		
		return low;
	}

	void main2(){
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		
		int t;
		for(t=1;t<=T;t++){
			BigInteger M = new BigInteger(scan.next());
			BigInteger C = new BigInteger(scan.next());
			int N = scan.nextInt();
			
			BigInteger price[] = new BigInteger[N];
			BigInteger day[] = new BigInteger[N];
			
			int i;
			for(i=0;i<N;i++){
				price[i] = new BigInteger(scan.next());
				day[i] = new BigInteger(scan.next());
				day[i] = day[i].add(BigInteger.ONE);
			}
			
			BigInteger ans = func(M, C, N, price, day);
			System.out.println("Case #" + t + ": " + ans); 
		}
	}

	public static void main(String args[]){
		C X = new C();
		X.main2();
	}

}
