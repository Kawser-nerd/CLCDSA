import java.util.*;
import java.io.*;

public class StandingOvation{
    
    static final String filename = "C:/Users/Kevin/algs4/CodeJam/StandingOvation/A-large.in";
    static final String output = "largefinaloutput.txt";
    
    public static int numOfFriends(int[] shylevels){
        int total = 0;
        int ret = 0;
        for(int i = 0; i < shylevels.length; ++i){
            ret = Math.max(ret, i - total);
            total += shylevels[i];
        }
        
        
        
        return ret;
    }
    
    
    
    
    
    
    
    public static void main(String[] args){
        try{
            Scanner sc = new Scanner(new FileInputStream(new File(filename)));
            int no_of_times = sc.nextInt();
            
            for(int i = 0; i < no_of_times; ++i){
                sc.nextInt();
                char[] shylevelchars = sc.nextLine().toCharArray();
                int[] shylevels = new int[shylevelchars.length-1];
                for(int j = 1; j < shylevelchars.length; ++j){
                    shylevels[j-1] = Integer.parseInt(((Character)shylevelchars[j]).toString());
                }
                
                FileOutputStream fos = new FileOutputStream(output, true);
                fos.write(("Case #" + (i+1) + ": " + numOfFriends(shylevels) + "\n").getBytes());
                fos.close();
                
                
            }
            sc.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    
    
    
    
    
}