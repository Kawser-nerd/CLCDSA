import java.util.*;

public class Main{      
    
    static int l[];
    static int r[];
    
    static int L;
    static int R;
    
    public static void main(String[] args){
      
        Scanner sc = new Scanner(System.in);
     
        boolean size[] = new  boolean[41];
        
        L = sc.nextInt();
        R = sc.nextInt();
        
        l = new int[L];
        r = new int[R];        
                
        for(int i = 0;i < L;i++){
            l[i] = sc.nextInt();
        }
        
        for(int i = 0;i < R;i++){
            r[i] = sc.nextInt();
        }
        
        int ans = 0;
        
        for(int i = 0;i < L;i++){            
            int target = l[i];
            if(size[target])
                 continue;            
            ans += Math.min(lcount(target),rcount(target));            
            size[target] = true;
        }
                
        System.out.println(ans); 
        
    }    
    
    static int lcount(int target){        
        int count = 0;
        for(int i = 0;i < L;i++){
             if(l[i] == target){
                 count++;
             }   
        }        
        return count;
    }
    
    static int rcount(int target){        
        int count = 0;
        for(int i = 0;i < R;i++){
            if(r[i] == target){
              count++;   
            }            
        }        
        return count;
    }
    
    
}