import java.util.*;

public class Main {

    private final static long MOD = 1000000007;
    
    public static long mul(long n,long m){
        return (n*m)%MOD;
    }
    
    public static long fact(long n){
        long ans = 1;
        for(long i = n;i>=1;i--){
             ans = mul(ans,i);   
        }        
        return ans;
    }
        
    public static void main(String[] args) {    	                 
            Scanner  s = new Scanner(System.in);        
       
            int N = s.nextInt();

            int t[] = new int[N];
            
            int counter[] = new int[10001];

            for(int i = 0;i < N;i++){
                t[i] = s.nextInt();
                counter[t[i]]++;
            }            
                        
            Arrays.sort(t);
            
            long currenttime = 0;
            long penalty     = 0;
            
            for(int time: t){
                currenttime += time;
                penalty     += currenttime;
            }                    
               
            long count = 1;
            for(int i = 0;i < counter.length;i++){
                count = mul(count,fact(counter[i])); 
            }                        
                      
            System.out.println(penalty);
            System.out.println(count);
        
    }
    
}