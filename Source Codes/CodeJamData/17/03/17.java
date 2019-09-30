package project;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.logging.Logger;

public class QR2017C {
	
	static Logger logger = Logger.getLogger(QR2017C.class.getName());
	static BufferedReader bis;
	static PrintWriter out;

	public static void main(String[] args){
		long startTime=System.currentTimeMillis();
		try{
			bis=new BufferedReader(new FileReader("QR2017C.in"));
			//bis=new BufferedReader(new InputStreamReader(System.in));
			out=new PrintWriter("QR2017C.out");

			String strNumTestCases=bis.readLine();
			int numTestCases=Integer.parseInt(strNumTestCases);
			long[] N=new long[numTestCases];
			long[] K=new long[numTestCases];

			for(int i=0;i<numTestCases;i++){
				String testCase=bis.readLine();
				testCase.trim();
				N[i]=Long.parseLong(testCase.split(" ")[0]);
				K[i]=Long.parseLong(testCase.split(" ")[1]);
			}

			for(int i=0;i<numTestCases;i++){
				long[] result=maxMin(N[i], K[i]);
				int index=i+1;
					//System.out.println("Case #"+index+": "+result[0]+" "+result[1]);			
					out.println("Case #"+index+": "+result[0]+" "+result[1]);			
			}

			out.flush();
			out.close();

			long endTime=System.currentTimeMillis();
			long timeInSec=(endTime-startTime)/1000;
			System.out.println("problem solved in secs:"+timeInSec);

		}
		catch(Exception e){
			e.printStackTrace();
		}

	}
	
	public static long[] maxMin(long N, long K){
		long[] maxMin=new long[2];
		if(K==1){
			if(N%2==0)//case N even
			{
				maxMin[0]=N/2;
				maxMin[1]=(N-1)/2;
			}
			else// case N odd
			{
				maxMin[0]=N/2;
				maxMin[1]=N/2;
			}
			return maxMin;
		}
		else if(K>1){
			if(N%2==1&&K%2==1)//both N and K are odd
			{
				return maxMin((N-1)/2,(K-1)/2);
				//return maxMin(N/2,K/2);
			}
			else if(N%2==0&&K%2==0)// both N and K are even
			{
				return maxMin(N/2,K/2);
			}
			else if(N%2==0&&K%2==1)// N is even, K is odd
			{
				return maxMin(N/2-1, (K-1)/2);
			}
			else if(N%2==1&&K%2==0)//N is odd, K is even
			{
				return maxMin((N-1)/2,K/2);
			}

		}
		return maxMin;
	}

}
