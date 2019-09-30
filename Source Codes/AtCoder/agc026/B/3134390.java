import java.util.*;

public class Main

{    //f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
	static long  gcd(long  x,long  y){
		if(y==0)return x;
		return gcd(y,x%y);
	}
    public static void main(String[] args)
	{
    	 Scanner in=new  Scanner(System.in);
    long a,b,c,d;
    int t=in.nextInt() ;
    while(t-->0) {
    a=in.nextLong();
    b=in.nextLong();
    c=in.nextLong();
    d=in.nextLong();
   	if(a<b||d<b)
   	{System.out.printf("No\n");
   	  continue;
   	}
   	if(c+1>=b)
   	{
   		System.out.printf("Yes\n");
   		continue;
   	}
   	long p=gcd(b,d);
   	if((a-c-1)/p-(a-b)/p>0)
   		System.out.printf("No\n");
   	else
   		System.out.printf("Yes\n");
   	//System.out.print(p);
   }

        
     }
 
}