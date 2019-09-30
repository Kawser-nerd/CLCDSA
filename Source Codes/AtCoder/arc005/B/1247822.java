import java.util.*;

public class Main {   
    
        private static int reverse(int x){
            int temp = x;
            if(9 < x){
                temp = 18 - x;
            }
            if(x < 1){
                temp = 2 - x;   
            }            
            return temp;
        }
        
        private static char get(char map[][],int y,int x){
              return map[reverse(y)][reverse(x)];
        }
    
	public static void main(String[] args) {
              Scanner sc = new Scanner(System.in);                                                                                     
         
              int x = sc.nextInt();
              int y = sc.nextInt();
              
              String W = sc.next();
              
              char map[][] = new char[10][10];
              
              for(int i = 1 ; i <= 9;i++){
                 String line = sc.next();
                 for(int j = 1;j <= 9;j++){
                     map[i][j] = line.charAt(j-1);   
                 }                 
              }              
              
              int dy = 0;
              int dx = 0;
              
              if(W.contains("R")){
                  dx = 1;
              }else if(W.contains("L")){
                  dx = -1;
              }
              
              if(W.contains("D")){                  
                  dy = 1;
              }else if(W.contains("U")){
                  dy = -1;
              }
  
              for(int i = 0 ;i < 4;i++){
                   System.out.print(get(map,y + i*dy,x + i*dx));
              }
              System.out.println();
        }        
}