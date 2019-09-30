import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader rd = new BufferedReader(new InputStreamReader(System.in), 1);
		String str = rd.readLine();
	    String[] sl = str.split(" ");
	    int n = Integer.parseInt(sl[0]);
	    int a = Integer.parseInt(sl[1]);
	    str = rd.readLine();
	    sl = str.split(" ");
	    int x[] = new int[51];
	    long v[][][] = new long[51][51][2501];
	    for(int i = 1; i <= n; i++)
		{
			x[i] = Integer.parseInt(sl[i - 1]);
		}
	    
	    v[1][1][x[1]] = 1;
	    v[1][0][0] = 1;
	    for(int i = 2; i <= n; i++)
	    {
	    	for(int j = 0; j <= i; j++)
	    	{
	    		for(int k = 0; k <= 50 * i; k++)
	    		{
	    			v[i][j][k] += v[i - 1][j][k];
	    		}
	    	}
	    	for(int j = 1; j <= i; j++)
	    	{
	    		for(int k = x[i]; k <= 50 * i; k++)
	    		{
	    			v[i][j][k] += v[i - 1][j - 1][k - x[i]];
	    		}
	    	}
	    }
	    
	    long ans = 0;
	    for(int i = 1; i <= n; i++)
	    {
	    	for(int j = 1; j <= n; j++)
	    	{
	    		ans += v[i][j][a * j] - v[i - 1][j][a * j];
	    	}
	    }
	    
		System.out.println(ans);
		
  	}
}