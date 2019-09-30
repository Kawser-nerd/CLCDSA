import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class C {

	Scanner scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	long mod =1000000007L;
	long solve(){
		long res=0;
		int n = scan.nextInt();
		int m = scan.nextInt();
		long X = scan.nextLong();
		long Y = scan.nextLong();
		long Z = scan.nextLong();
		long[] A = new long[m];
		for(int i=0;i<m;i++)A[i]=scan.nextLong();
		long[] B = new long[n];
		TreeSet<Long>vals = new TreeSet<Long>();
		HashMap<Long, Integer> compress = new HashMap<Long, Integer>();
		for(int i=0;i<n;i++){
			B[i]=A[i%m];
			A[i%m]= (X*A[i%m] + Y *(i+1))%Z;
			vals.add(B[i]);
		}
		int num =1;
		for(long x:vals)compress.put(x, num++);
		BinaryInd bind = new BinaryInd();
		for(int i=0;i<n;i++){
			int x = compress.get(B[i]);
			long r =1;
			if(x !=1){
				r += bind.getSum(1, x-1);
				r%=mod;
			}
			res+=r;
			res%=mod;
			bind.add(x, r);
		}
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			System.out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	C() throws Exception{
		in = new BufferedInputStream(new FileInputStream("C-large.in"));
		//in = new BufferedInputStream(new FileInputStream("C.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new C().solveAll();
	}

    class BinaryInd {
        int MAX ;
        long P[];
        public BinaryInd(int size){
            MAX=size;
            P = new long[MAX+1];
        }
        public BinaryInd(){
            this(1000000);
        }
        
        public void add(int ind, long x){
            while(ind<=MAX){
                P[ind]+=x;
                ind += ind & (-ind);
            }
        }
        
        public long getSum( int ind){
            long res =0;
            while(ind>0){
                res += P[ind];
                ind -= ind & (-ind);
            }
            return res;
        }
        /** inclusive **/
        public long getSum(int a, int b){
            return getSum(b) - getSum(a-1);
        }
        
        public long get(int ind){
            return getSum(ind)-getSum(ind-1);
        }
    }
}
