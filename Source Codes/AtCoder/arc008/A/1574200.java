import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
    Scanner sc = new Scanner(System.in);          
               
    int N = sc.nextInt();
    
    int count = 0;
    
    while(N - 10 >= 0){
        count++;
        N -= 10;
    }
    
    if(N >= 7){
        count++;
        System.out.println(100*count);        
        return;
    }else{
        System.out.println(N*15 + 100*count);
        return;
    }
     
  }                            
}