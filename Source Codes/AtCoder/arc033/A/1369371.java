import java.util.*;

public class Main {    
    
    public static void main(String[] args){
       
       Scanner sc = new Scanner(System.in);
        
       int N = sc.nextInt();
                                      
       int total = 0;

       for(int i = 1;i <= N;i++){
             int count = 1;
             count +=  N - i;
             total += count;
       }
       
       System.out.println(total);
       
    }      
}