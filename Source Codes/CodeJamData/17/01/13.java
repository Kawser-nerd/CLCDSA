package project;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.logging.Logger;

public class QR2017A {

	static Logger logger = Logger.getLogger(QR2017A.class.getName());
	static BufferedReader bis;
	static PrintWriter out;

	public static void main(String[] args){
		long startTime=System.currentTimeMillis();
		try{
			bis=new BufferedReader(new FileReader("QR2017A.in"));
			//bis=new BufferedReader(new InputStreamReader(System.in));
			out=new PrintWriter("QR2017A.out");
			//out=new PrintWriter("System.out");

			String strNumTestCases=bis.readLine();
			int numTestCases=Integer.parseInt(strNumTestCases);
			String[] S=new String[numTestCases];
			int[] K=new int[numTestCases];

			for(int i=0;i<numTestCases;i++){
				String testCase=bis.readLine();
				testCase.trim();
				S[i]=testCase.split(" ")[0];
				K[i]=Integer.parseInt(testCase.split(" ")[1]);
			}

			for(int i=0;i<numTestCases;i++){
				int result=calculateCount(new StringBuffer(S[i]), K[i]);
				int index=i+1;
				if(result==-1){
					//System.out.println("Case #"+index+": IMPOSSIBLE");
					out.println("Case #"+index+": IMPOSSIBLE");
				}
				else{
					//System.out.println("Case #"+index+": "+result);			
					out.println("Case #"+index+": "+result);			
				}
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
	
	public static int calculateCount(StringBuffer S, int K){
		int length=S.length();
		int min=0, flipCount=0;
		int firstMinusPos=0;
		do{
			firstMinusPos=findFirstMinusPos(S, min);
			min=K*(firstMinusPos/K);
			//logger.info(" firstMinusPos: "+firstMinusPos+ " min:"+min);

			if(firstMinusPos==length)
				return flipCount;
			else if(firstMinusPos+K<=length){
				flip(S, firstMinusPos,K);		
				flipCount++;
			}
			else if(firstMinusPos+K>length)
				return -1;
		}
		while(firstMinusPos<=length);
				
		return -1;
	}
	
	public static void flip(StringBuffer S, int firstMinusPos, int length){
		for(int i=0;i<length;i++){
			if(S.charAt(firstMinusPos+i)=='-')
				S.setCharAt(firstMinusPos+i, '+');
			else
				S.setCharAt(firstMinusPos+i, '-');
		}
	}
	
	public static int findFirstMinusPos(StringBuffer S, int min){
		int firstMinusPos=min;
		while(firstMinusPos<S.length()){
			if(S.charAt(firstMinusPos)=='-'){
				break;
			}
			firstMinusPos++;
		}
		return firstMinusPos;

	}
}
