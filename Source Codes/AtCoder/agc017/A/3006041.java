import java.util.Scanner;

public class Main {
	  
	public static void main(String args[]) {
		    Scanner scanner = new Scanner(System.in);
		    
		    int N = scanner.nextInt();
		    int P = scanner.nextInt();
		    int[] array = new int[N];
		    int count0 = 0;
		    int count1 = 0; 
		    
		    for( int i = 0; i < N; i++ ) 
		    {
		    	array[i] = scanner.nextInt() % 2;
		    	if( array[i] == 1 ) 
		    	{
		    		count1 = count1 + 1;
		    	}
		    	else 
		    	{
		    		count0 = count0 + 1;
		    	}
		    }
		    if( count1 == 0 ) 
		    {
		    	if( P == 1 ) 
		    	{
		    		System.out.println(0);
		    	}
		    	else 
		    	{
		    		System.out.println((long)Math.pow( 2, N ));
		    	}
		    }
		    else
		    {
		    	System.out.println( (long)Math.pow( 2,N-1 ) );
		    }
		    scanner.close(); }
		  }