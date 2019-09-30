package project;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.logging.Logger;

public class QR2017B {
	
	static Logger logger = Logger.getLogger(QR2017B.class.getName());
	static BufferedReader bis;
	static PrintWriter out;

	public static void main(String[] args){
		long startTime=System.currentTimeMillis();
		try{
			bis=new BufferedReader(new FileReader("QR2017B.in"));
			//bis=new BufferedReader(new InputStreamReader(System.in));
			out=new PrintWriter("QR2017B.out");

			String strNumTestCases=bis.readLine();
			int numTestCases=Integer.parseInt(strNumTestCases);
			long[] N=new long[numTestCases];

			for(int i=0;i<numTestCases;i++){
				String testCase=bis.readLine();
				testCase.trim();
				N[i]=Long.parseLong(testCase);
			}

			for(int i=0;i<numTestCases;i++){
				long result=calculateNum(N[i]);
				int index=i+1;
					//System.out.println("Case #"+index+": "+result);			
					out.println("Case #"+index+": "+result);			
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
	
	public static long calculateNum(long N){
		String strN=String.valueOf(N);
		long revNum=N;
		
		int numDigits=strN.length();
		//logger.info(" numdigits "+numDigits);

		if(numDigits==1)
			return N;
		
		int minDisagreeingPlace=numDigits-1;
		while(minDisagreeingPlace>0){
			//logger.info(" revised num"+revNum);
			//logger.info(" minDisagreeingPlace"+minDisagreeingPlace);
			long digit=revNum/(long)Math.pow(10,minDisagreeingPlace);
			long revNum1=revNum%(long)Math.pow(10,minDisagreeingPlace);
			long nextDigit=revNum1/(long)Math.pow(10,minDisagreeingPlace-1);
			//logger.info("digit "+digit+ " nxtDigit "+nextDigit);
			if(nextDigit<digit){
				revNum=N/(long)Math.pow(10,minDisagreeingPlace);
				revNum=revNum*(long)Math.pow(10, minDisagreeingPlace);
				/* above two operation diminishes every digit after non-disagreeing digit to 0*/
				revNum=revNum-1;
				N=revNum;
				minDisagreeingPlace=numDigits-1;
			}			
			else{
				revNum=revNum%(long)Math.pow(10,minDisagreeingPlace);
				minDisagreeingPlace--;
			}
		}		
		return N;
	}
}
