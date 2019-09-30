package project;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.logging.Logger;

public class QR2017DB {
	static Logger logger = Logger.getLogger(QR2017DB.class.getName());
	static BufferedReader bis;
	static PrintWriter out;
	
	static ArrayList<String> retList=null;

	public static void main(String[] args){
		long startTime=System.currentTimeMillis();
		try{
			bis=new BufferedReader(new FileReader("QR2017D.in"));
			//bis=new BufferedReader(new InputStreamReader(System.in));
			out=new PrintWriter("QR2017D.out");

			String strNumTestCases=bis.readLine();
			int numTestCases=Integer.parseInt(strNumTestCases);
			int[] N=new int[numTestCases];
			int[] M=new int[numTestCases];
			char[][][] Grids=new char[numTestCases][][];
			char[][][] GridsB=new char[numTestCases][][];

			for(int i=0;i<numTestCases;i++){
				String testCase=bis.readLine();
				testCase.trim();
				N[i]=Integer.parseInt(testCase.split(" ")[0]);
				M[i]=Integer.parseInt(testCase.split(" ")[1]);
				char[][] Grid=new char[N[i]][N[i]];	
				char[][] GridB=new char[N[i]][N[i]];	
				for(int j=0;j<M[i];j++){
					String modelTestCase=bis.readLine();
					char model=modelTestCase.split(" ")[0].charAt(0);
					int rowNum=Integer.parseInt(modelTestCase.split(" ")[1]);
					int colNum=Integer.parseInt(modelTestCase.split(" ")[2]);
					Grid[rowNum-1][colNum-1]=model;
					GridB[rowNum-1][colNum-1]=model;
				}
				Grids[i]=Grid;
				GridsB[i]=GridB;
			}

			for(int i=0;i<numTestCases;i++){
				int[] result=computeResult(Grids[i],GridsB[i],N[i]);
				int index=i+1;
					out.println("Case #"+index+": "+result[0]+" "+result[1]);
					for(String str:retList){
						out.println(str);
					}
//					System.out.println("Case #"+index+": "+result[0]+" "+result[1]);
//					for(String str:retList){
//						System.out.println(str);
//					}
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
	
	
	public static int[] computeResult(char[][] Grid, char[][] GridB, int N){
		int result[]=new int[2];
		retList=new ArrayList<String>();
		
		int score=0, count=0;
		int i=N-1;
		while(i>=0){
			for(int j=i;j>=0;j--){
				int res[]=compute(Grid, N, i, j);
				score+=res[0];
				count+=res[1];
			}
			
			for(int k=i-1;k>=0;k--){
				int res[]=compute(Grid, N, k, i);
				score+=res[0];
				count+=res[1];
			}			
			i--;
		}
				
		result[0]=score;
		result[1]=count;

//		System.out.println();
//		
//		for(i=0;i<N;i++){
//			System.out.println();
//			for(int j=0;j<N;j++){
//				if(Grid[i][j]==0)
//					System.out.print(" "+".");
//				else
//					System.out.print(" "+Grid[i][j]);
//			}
//		}
		
		return result;
	}
	
	
	public static int[] compute(char[][] Grid, int N, int i, int j){
		int[] result=new int[2];
		if(Grid[i][j]!=0)//already initialized
		{
			if(Grid[i][j]=='o'){
				result[0]+=2;
			}
			else{
				char oldChar=Grid[i][j];
				Grid[i][j]='o';
				if(checkDiagonals(Grid, N, i, j)&&checkVerticalHorizontal(Grid,N,i,j)){
					result[0]+=2;
					result[1]++;
					retList.add("o "+(i+1)+" "+(j+1));
				}
				else{
					Grid[i][j]=oldChar;
					result[0]++;

				}
			}
			
		}
		else//uninitialized cell
		{
			Grid[i][j]='o';
			if(checkDiagonals(Grid, N, i, j)&&checkVerticalHorizontal(Grid,N,i,j)){
				result[0]+=2;
				result[1]++;
				retList.add("o "+(i+1)+" "+(j+1));
				return result;
			}
			Grid[i][j]='+';
			if(checkDiagonals(Grid, N, i, j)){
				result[0]+=1;
				result[1]++;
				retList.add("+ "+(i+1)+" "+(j+1));
				return result;
			}
			Grid[i][j]='x';
			if(checkVerticalHorizontal(Grid, N, i, j)){
				result[0]+=1;
				result[1]++;				
				retList.add("x "+(i+1)+" "+(j+1));
				return result;
			}
			else{
				Grid[i][j]=0;
			}
		}
		return result;

	}
	
	public static boolean checkDiagonals(char[][] Grid, int N, int posi, int posj){
	
		if(Grid[posi][posj]=='x')
			return true;
		else{
			int i=posi;
			int j=posj;
			//Scan north west
			while(i>0&&j>0){
				i--;
				j--;
				if(Grid[i][j]=='o'||Grid[i][j]=='+')
					return false;
			}
			
			i=posi;
			j=posj;
			//Scan north east
			while(i>0&&j<N-1){
				i--;
				j++;
				if(Grid[i][j]=='o'||Grid[i][j]=='+')
					return false;

			}

			i=posi;
			j=posj;
			//Scan south east
			while(i<N-1&&j>0){
				i++;
				j--;
				if(Grid[i][j]=='o'||Grid[i][j]=='+')
					return false;

			}
			
			i=posi;
			j=posj;
			//Scan south east
			while(i<N-1&&j<N-1){
				i++;
				j++;
				if(Grid[i][j]=='o'||Grid[i][j]=='+')
					return false;

			}
		}
		return true;
	}
	
	
	public static boolean checkVerticalHorizontal(char[][] Grid, int N, int posi, int posj){
		
		if(Grid[posi][posj]=='+')
			return true;
		else{
			int i=posi;
			int j=posj;
			//Scan north 
			while(i>0){
				i--;
				if(Grid[i][j]=='o'||Grid[i][j]=='x')
					return false;
			}
			
			i=posi;
			j=posj;
			//Scan south
			while(i<N-1){
				i++;
				if(Grid[i][j]=='o'||Grid[i][j]=='x')
					return false;

			}

			i=posi;
			j=posj;
			//Scan west
			while(j>0){
				j--;
				if(Grid[i][j]=='o'||Grid[i][j]=='x')
					return false;

			}
			
			i=posi;
			j=posj;
			//Scan east
			while(j<N-1){
				j++;
				if(Grid[i][j]=='o'||Grid[i][j]=='x')
					return false;

			}
		}
		return true;
	}
}
