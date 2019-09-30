import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		// TODO Auto-generated method stub
		ArrayList<BigInteger> a = new ArrayList<BigInteger>(); 
		int i,j,k;

		a.add(new BigInteger("0"));
		a.add(new BigInteger("1"));
		a.add(new BigInteger("2"));
		a.add(new BigInteger("11"));
		a.add(new BigInteger("22"));
		BigInteger _2 = new BigInteger("2");
		
		int size=4;
		
		for(int len=3;len<=50;++len){
			ArrayList<BigInteger> b = new ArrayList<BigInteger>();
			BigInteger pr = BigInteger.TEN.pow(len-1);
			BigInteger sf = BigInteger.ONE;
			for(BigInteger y:a){
				int dlen=y.toString().length();
				if(y.signum()!=0 && dlen%2!=len%2) continue;
				BigInteger dy = y.multiply(BigInteger.TEN.pow((len-dlen)/2));
				BigInteger x = pr.add(dy).add(sf);
				if(pal(x) && pal(x.pow(2))){
					b.add(x);
				}
			}
			b.add(_2.multiply(BigInteger.TEN.pow(len-1)).add(_2));
			if(len%2==1)b.add(_2.multiply(BigInteger.TEN.pow(len-1)).add(_2).add(BigInteger.TEN.pow(len/2)));
			for(BigInteger x:b){
				//System.out.println(x);
				//System.out.flush();
				
				++size;
			}
			a.addAll(b);
		}
		a.add(new BigInteger("3"));
		
		ArrayList<BigInteger> sqa = new ArrayList<BigInteger>();
		for(BigInteger x:a) sqa.add(x.pow(2));
		
		int t = in.nextInt();
		for(int ti=1;ti<=t;++ti){
			BigInteger L = in.nextBigInteger();
			BigInteger R = in.nextBigInteger();
			int ans=0;
			for(BigInteger y:sqa){
				if(L.compareTo(y)<=0 && y.compareTo(R)<=0) ++ans;
			}
			out.println("Case #"+ti+": "+ans);
		}
		out.close();
		
		
		
	}
	
	static boolean pal(BigInteger x){
		char s[] = x.toString().toCharArray();
		for(int i=0,j=s.length-1; i<j; ++i,--j) if(s[i]!=s[j]) return false;
		return true;
	}

}
