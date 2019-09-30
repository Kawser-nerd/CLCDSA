import java.util.*;
import java.lang.*;
import java.io.*;


public class Main {

    static final int MOD = 1_000_000_007;
    
    public static long addMod(long a, long b){
    	long tmp = (a+b)%MOD;
    	return tmp>=0 ? tmp : tmp+MOD;
    }
    public static long subMod(long a, long b){
    	return addMod(a,-b);
    }
    public static long multMod(long a, long b){
    	long tmp = (a*b)%MOD;
    	return tmp>=0 ? tmp : tmp+MOD;
    }
    public static long powerMod(long a, long x){ //calculate a^x
        if(x<0)return 0;
        if(x==0)return 1;
        if(x%2==0) {
        	long half = powerMod(a,x/2);
        	return multMod(half,half);
        }
        return (a*powerMod(a,x-1)) % MOD;
    }
    public static long inverseMod(long a){
        return powerMod(a,MOD-2);
    }
    public static long divMod(long a, long b){
    	return multMod(a, inverseMod(b));
    }

    public static long[] makeFactorialArray(int size){
        long[] array = new long[size];
        array[0]=1;
        for(int i=1;i<size;i++){
        	array[i]=multMod(array[i-1],i);
        }
        return array;
    }
    public static long[] makeInversedArray(long[] original){
        long[] array = new long[original.length];
        for(int i=0;i<original.length;i++){
        	array[i] = inverseMod(original[i]);
        }
        return array;
    }
    public static long combination(int n, int r, long[] fact, long[] factInv){
        return multMod(fact[n], multMod(factInv[r],factInv[n-r]));
    }
    
/*7 9 3 4
 012345678
0.......!.
1......!..
2.....!...
3....!....
4####.....
5####.....
6####.....
*/
    public static void main(String[] args) {
        
        long[] fact = makeFactorialArray(200001);
        long[] factInv = makeInversedArray(fact);
        
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        
        int h = H-1-A;
        int w = B;
        long ans = 0;
        
        while(h>=0 && w<W){
        	
        	ans = addMod(ans, multMod(combination(h+w,h,fact,factInv),combination(H+W-h-w-2,H-1-h,fact,factInv)));
        	h--;w++;
        }
        
        System.out.println(ans);
        
    }
}