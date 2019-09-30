import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;


public class PartElf {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new FileReader(new File("in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("out")));
		StringTokenizer st;
				
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			st=new StringTokenizer(br.readLine(),"/");
			long P=Long.parseLong(st.nextToken());
			long Q=Long.parseLong(st.nextToken());
			long gcd=gcd(P,Q);
			P/=gcd; Q/=gcd;
			int ans=solve(P,Q);
			
			System.out.println();
			bw.append("Case #"+cn+": ");
			if(ans==-1)
				bw.append("impossible\n");
			else
				bw.append(ans+"\n");
		}
		bw.flush();

	}
	static int solve(long P, long Q){
		//check if Q is power of two
		System.out.println(P+" "+Q);
		long qq=Q;
		while((qq&1)==0)
			qq>>=1;
		if(qq!=1)
		return -1;
		
		int ret=0;
		while(P<Q){
			Q>>=1;
			ret++;
		}
		
		return ret;
	}
	static long gcd(long a, long b){
		if(b==0)
			return a;
		else
			return gcd(b,a%b);
	}
}
