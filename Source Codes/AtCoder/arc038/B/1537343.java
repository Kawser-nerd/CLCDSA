import java.util.*;

public class Main{      
    
    public static void main(String[] args){
       
        Scanner sc = new Scanner(System.in);             
                
        int h = sc.nextInt();
        int w = sc.nextInt();
        
        boolean[][] block = new boolean[h+1][w+1];
        
        for (int i = 0; i <= h; i++) {
          block[i][w] = true;
        }
        
        Arrays.fill(block[h], true);
    
     for(int i = 0; i < h; i++) {
       String line = sc.next();
       char[] array = line.toCharArray();
       for (int j = 0; j < w; j++) {
         block[i][j] = (array[j] == '#');
       }
     }
 
     boolean[][] win = new boolean[h+1][w+1];
     
     for (int i = h; i >= 0; i--) {
      for (int j = w; j >= 0; j--) {
        if (block[i][j]) {
          win[i][j] = true;
        } else if (win[i+1][j] && win[i+1][j+1] && win[i][j+1]) {
          win[i][j] = false;
        } else {
          win[i][j] = true;
        }
      }
    }
     
 System.out.println(win[0][0] ? "First" : "Second");
        
   }          
}