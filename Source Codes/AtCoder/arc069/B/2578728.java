import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader rd = new BufferedReader(new InputStreamReader(System.in), 1);
		String str = rd.readLine();
	    int n = Integer.parseInt(str);
	    str = rd.readLine();
	    boolean s[] = new boolean[100003];
	    boolean a[] = new boolean[100003];
	    
	    // T => x   F => o 
	    for(int i = 0; i <= 100002; i++)
		{
			s[i] = str.charAt(i % n) == 'x';
		} 
	    
	    a[0] = a[1] = false;
	    for(int i = 1; i <= n + 1; i++)
	    {
	    	a[i + 1] = a[i] ^ s[i] ^ a[i - 1];
	    }  
	    		
	    if(a[0] == a[n] && a[1] == a[n + 1])
	    {
	    	for(int i = 0; i < n; i++)
	    	{
	    		System.out.print(a[i] ? 'W' : 'S');
	    	}
	    	System.exit(0);
	    }
	    
	    a[0] = true;
	    a[1] = false;
	    for(int i = 1; i <= n + 1; i++)
	    {
	    	a[i + 1] = a[i] ^ s[i] ^ a[i - 1];
	    }  
	    		
	    if(a[0] == a[n] && a[1] == a[n + 1])
	    {
	    	for(int i = 0; i < n; i++)
	    	{
	    		System.out.print(a[i] ? 'W' : 'S');
	    	}
	    	System.exit(0);
	    }
	    
	    a[0] = false;
	    a[1] = true;
	    for(int i = 1; i <= n + 1; i++)
	    {
	    	a[i + 1] = a[i] ^ s[i] ^ a[i - 1];
	    }  
	    		
	    if(a[0] == a[n] && a[1] == a[n + 1])
	    {
	    	for(int i = 0; i < n; i++)
	    	{
	    		System.out.print(a[i] ? 'W' : 'S');
	    	}
	    	System.exit(0);
	    }
	    
	    a[0] = a[1] = true;
	    for(int i = 1; i <= n + 1; i++)
	    {
	    	a[i + 1] = a[i] ^ s[i] ^ a[i - 1];
	    }  
	    		
	    if(a[0] == a[n] && a[1] == a[n + 1])
	    {
	    	for(int i = 0; i < n; i++)
	    	{
	    		System.out.print(a[i] ? 'W' : 'S');
	    	}
	    	System.exit(0);
	    }
	    
	    System.out.println(-1);
		
  	}
}