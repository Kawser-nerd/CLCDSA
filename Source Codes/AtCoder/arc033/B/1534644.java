import java.util.*;

public class Main{      
    
    public static void main(String[] args){
       
        Scanner sc = new Scanner(System.in);
        
        int NA = sc.nextInt();
        int NB = sc.nextInt();
                
        HashSet A = new HashSet<>();
        for(int i = 0;i < NA;i++){
            A.add(sc.nextInt());
        }
        
        int cnt = 0;
        
        for(int i = 0 ;i < NB;i++){
            int target = sc.nextInt();
            if(A.contains(target)){
                cnt++;
            }else{
               A.add(target);
            }            
        }
       
        System.out.println((double) cnt/A.size());
                
    }
    
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.