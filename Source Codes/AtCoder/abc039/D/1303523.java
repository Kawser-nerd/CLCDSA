import java.util.*;

public class Main {
	public static void main(String[] args) {
		 
            Scanner sc = new Scanner(System.in);
            
            int H = sc.nextInt();
            int W = sc.nextInt();
            
            char ans[][] = new char[H][W];
            
            int dx[] = {-1,-1,0,1,1, 1, 0,-1};
            int dy[] = {0 , 1,1,1,0,-1,-1,-1};
            
            for(char[] row: ans)
                 Arrays.fill(row,'#');
            
            char start[][] = new char[H][W];
            
            // Restoration
            for(int i = 0;i < H;i++){
                String S = sc.next();
                for(int j = 0;j < W;j++){                                        
                    start[i][j] = S.charAt(j);
                    if(S.charAt(j) == '.'){                                                    
                        ans[i][j] = '.';
                        for(int k = 0;k < 8;k++){
                            int ny = i + dy[k]; 
                            int nx = j + dx[k];
                            if(ny < 0 || ny >= H || nx < 0 || nx >= W){       
                                  continue;  
                            }
                            ans[ny][nx] = '.';                            
                        }                        
                    }                    
                }                
            }
            
            char A[][] = new char[H][W];
            
            for(char[] row:A)
                Arrays.fill(row,'.');
            
            // Contraction            
            for(int i = 0;i < H;i++){
                for(int j = 0;j < W;j++){
                    if(ans[i][j] == '#'){
                       A[i][j] = '#';
                       for(int k = 0;k < 8;k++){
                           int ny = i + dy[k];
                           int nx = j + dx[k];
                           if(ny < 0 || ny >= H || nx < 0 || nx >= W){
                                   continue;    
                           }
                           A[ny][nx] = '#';          
                       }                        
                    }                    
                }                
            }
            
            
            String ok = "possible";
            
            for(int i = 0;i < H;i++){
                for(int j = 0;j < W;j++){
                    if(start[i][j] != A[i][j]){
                       ok = "impossible";
                       System.out.println(ok);
                       return;
                    }                    
                }                                
            }
            
            System.out.println(ok);
            
            for(int i = 0;i < H;i++){
                for(int j = 0;j < W;j++){
                    System.out.print(ans[i][j]);   
                }                
                System.out.println();
            }            
            
        }        
}