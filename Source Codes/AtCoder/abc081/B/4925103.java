import java.util.*;

public class Main {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        
        long[] a = new long[n];
        
        for(int i = 0; i < n; i++){
            a[i] = Long.parseLong(sc.next());
        }
        
        int count = 0;
        
        loop: while(true){
            for(int i = 0; i < a.length; i++){
                if(a[i] % 2 != 0){
                    break loop;
                }else{
                    a[i] /= 2;
                }
            }
            count++;
        }
        System.out.println(count);
    }
}