import java.util.*;

public class Main{
    
    static int counter = 0;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int k = sc.nextInt();
        
        int[] fib = new int[45];
        fib[0] = 1;
        fib[1] = 1;
        for(int i=1; i<fib.length-1; i++){
            fib[i+1] = fib[i] + fib[i-1];
        }
        
        System.out.println(fib[k+1] + " " + fib[k]);
        //System.out.println(gcd(fib[k+1], fib[k]));
        //System.out.println(counter);
    }
    
    public static int gcd(int a, int b){
        if (b == 0) return a;
        counter++;
        return gcd(b, a%b);
    }
}