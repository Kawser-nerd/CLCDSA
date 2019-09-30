import java.util.*;
import java.io.*;

public class Ominous{
    
    static final String filename = "C:/Users/Kevin/algs4/CodeJam/Ominous/D-large.in";
    static final String output = "largeoutput.txt";
    
    
    public static boolean canRichWin(int X, int R, int C){
        if(R > C) return canRichWin(X, C, R);
        if(X >= 7) return true;
        if((R*C)%X != 0) return true;
        if(X < 3) return false;
        if(X > C) return true;
        if((X+1)/2 > R) return true; //L shape
        if(X == 3) return false;
        if(R == 2) return true;
        
        if(X==4) return false;
        //X is 5,6. C is at least X. R is at least 3, 3.
        if(X==5){
            if(R==3){
                if(C==5) return true; // diagonal W
                return false;
            }
            return false;
        }
        
        if(R==3) return true;
        return false;
        
        
        
        
        
    }
    
    
    
    
    public static void main(String[] args){
      try{
            Scanner sc = new Scanner(new FileInputStream(new File(filename)));
            int no_of_times = sc.nextInt();
            
            for(int i = 0; i < no_of_times; ++i){
                int X = sc.nextInt();
                int R = sc.nextInt();
                int C = sc.nextInt();
                
                
                
                FileOutputStream fos = new FileOutputStream(output, true);
                fos.write(("Case #" + (i+1) + ": " + (canRichWin(X,R,C) ? "RICHARD" : "GABRIEL") +  "\n").getBytes());
                fos.close();
                
                
            }
            sc.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
        
    }
    
    
    
    
    
}