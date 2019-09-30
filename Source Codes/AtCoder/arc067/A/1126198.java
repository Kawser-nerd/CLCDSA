import java.io.*;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
   
    static int a[]=new int[1000];
    
    public static void main(String[] args) {

	Scanner sc = new Scanner(System.in);
	
	int N=sc.nextInt();
	
	ArrayList<Integer> ar=new ArrayList();
	//ar.add(1);
	
	  for (int i = 2; i < 1000; i++) {
	      boolean t =true;
	      for (int j = 2;t&& j < i; j++) {
		  if(i%j==0)
		      t=false;
	      }
	      
	      if (t) {
		  ar.add(i);
	      }
	      
	      
	}
 
	  int n=ar.size();
	  int c[]=new int[n];
	  long ans = 0;
	  
	  for (int i = N; i >1; i--) {
	    int q=i;
	  int co=0;
	      boolean tfftf = true;
	      for (int j = 0;tfftf &&j < n; j++) {
		  
		  int aaa=ar.get(j);
		 
		 
		 
		 
		  while(q%aaa==0){
		      q/=aaa;
		      c[j]++;
		  }
		  
		  if(q==1)
		      tfftf=false;
		  
	      }
	}
	  
	  ans=1;
	  for (int i = 0; i < n; i++) {
	    if(c[i]!=0)
	    ans*=c[i]+1;
	    ans%=1000000007;
	}
	  
	  
	  System.out.println(ans);
	
    }
    
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.