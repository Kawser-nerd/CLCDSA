package googlejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.*;

public class WateringPlants {
	static int[] x;
	static int[] y;
	static int[] r;
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in=new BufferedReader(new FileReader("c:\\D-small-attempt0.in.txt"));
		PrintWriter pr=new PrintWriter(new FileWriter("C:\\D-small0.out.txt"));
		
        int T=Integer.parseInt(in.readLine().trim());
		
        
		for(int i=0;i<T;i++)
		{
			int N=Integer.parseInt(in.readLine().trim());
		    
			x=new int[N];
			y=new int[N];
			r=new int[N];
			
			for(int j=0;j<N;j++)
	        {
				String[]temp=in.readLine().trim().split("[ ]+");
				x[j]=Integer.parseInt(temp[0]);
				y[j]=Integer.parseInt(temp[1]);
				r[j]=Integer.parseInt(temp[2]);
	        }
			if(N==1)
				pr.println("Case #"+(i+1)+": "+r[0]);
			else if(N==2)
				pr.println("Case #"+(i+1)+": "+(r[0]>r[1]?r[0]:r[1]));
			else{
			double result=findmin(0);
			for(int j=1;j<N;j++)
			{
			//	System.out.println(j+" "+findmin(j));
				if(result>findmin(j))
					result=findmin(j);
			}
			pr.println("Case #"+(i+1)+": "+result);
			}
			}
		pr.close();
	}
	
	static double findmin(int now)
	{
		
		if(now==0)
		{
			double result=r[0];
			double t1=(r[1]+r[2]+Math.sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2])))/2.0;
		    return result>t1?result:t1;
		}
		if(now==1)
		{
			double result=r[1];
			double t1=(r[0]+r[2]+Math.sqrt((x[2]-x[0])*(x[2]-x[0])+(y[2]-y[0])*(y[2]-y[0])))/2.0;
		    return result>t1?result:t1;
		}
		else 
		{
			double result=r[2];
			double t1=(r[1]+r[0]+Math.sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0])))/2.0;
		    return result>t1?result:t1;
		}
		
	}
}
