import java.util.*;

public class Main{      

    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        int ans = 0;
        
        char[][] music = new char[N][9];
        
        for(int i = 0;i < N;i++){
           String s = sc.next();
           for(int j = 0;j < 9;j++){
               music[i][j] = s.charAt(j);
               if(music[i][j] == 'x')
                   ans++;
           }           
        }
      
        for(int j = 0;j < 9;j++){
            int flg = 0;            
            for(int i = 0 ;i < N;i++){
                  if(music[i][j] == 'o' && flg == 0){
                      flg = 1;
                      ans++;
                  }else if(music[i][j] != 'o'){
                      flg = 0;
                  }                                                
            }                        
        }
        
        System.out.println(ans);
        
    }
                         
}