import java.util.*;

class Main{            
     
   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);  

       
       int n = sc.nextInt();
       
       int [] l = new int[n];
       
       int min = Integer.MAX_VALUE;
       
       for(int i = 0;i < n;i++){
           l[i] = sc.nextInt();
           min = Math.min(min,l[i]);
       }
       
       int gcd = 0;
       
       for(int i = 0;i < n;i++){
           gcd = gcd(gcd,l[i] - min);
       }
       
       System.out.println(pow(2,min + (gcd + 1)/2));
       
   }       
   
   private static final int MOD = 1_000_000_007;

   private static int gcd(int n,int m){
       if(m == 0){
           return n;
       }else{
           return gcd(m,n%m);
       }       
   }
   
   private static long pow(int a,long n){
       long loop = n;
       long ret = 1;
       long x = a;
       while(loop > 0){
          if(loop%2 == 1){
              ret = ret*x%MOD;
          } 
          x = x*x%MOD;
          loop /= 2;
       }            
       
       return ret;
   }
   
}