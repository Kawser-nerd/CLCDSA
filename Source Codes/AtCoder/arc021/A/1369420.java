import java.util.*;

public class Main {    
    
    public static void main(String[] args){
       
         Scanner sc = new Scanner(System.in);       
      
         int a[][] = new int[4][4];
         
        for(int y = 0;y < 4;y++){
            for(int x = 0 ;x < 4;x++){
                a[y][x] = sc.nextInt();
            }             
        }
        
        int dx[] = {-1,0,1, 0};
        int dy[] = { 0,1,0,-1};
        
        for(int y = 0;y < 4;y++){
            for(int x = 0; x < 4;x++){
                for(int i = 0;i < 4;i++){
                   int ny = y + dy[i];
                   int nx = x + dx[i];
                   if(nx < 0 || nx > 3 || ny < 0 || ny > 3)
                       continue;
                                      
                   if(a[y][x] == a[ny][nx]){
                        System.out.println("CONTINUE");
                        return;
                   }
                }
            }              
        }      
        
        System.out.println("GAMEOVER");
      
    }      
}