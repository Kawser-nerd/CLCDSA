import java.util.*;

public class Main{    
    
    static boolean masu[];
    
    public static void main(String[] args){            
       
        Scanner sc = new Scanner(System.in);        
                      
        int N = sc.nextInt();
        int R = sc.nextInt();
        
        String S = sc.next();
        
        int lastindex = -1;
        
        masu = new boolean[N];
        
        int last = 0;
        for(int i = 0 ;i < N;i++){
            masu[i] = S.charAt(i) == 'o';
            if(!masu[i]){
                last = i+1;
            }
        }
        
        int ans = 0;
        int idx = 1;
        
        while(true){
            if(check())break;                                  
            if(last - idx < R){
                ans++;
                break;
            }else if(masu[idx-1]){
                ans++;
                idx++;
            }else{
                ans++;
                for(int i = idx;i < idx + R;i++){
                    masu[i-1] = true;
                }
            }                        
        }
        System.out.println(ans);
        
    }                           
    
    static boolean check(){
      for(int i = 0;i < masu.length;i++){
          if(!masu[i]) return false;
      }
      return true;
    }
    
}