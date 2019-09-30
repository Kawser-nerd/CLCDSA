import java.util.*;
import java.io.*;

public class InfinitePancakes{
    static final String filename = "C:/Users/Kevin/algs4/CodeJam/InfinitePancakes/B-large.in";
    static final String output = "largeoutput.txt";
    
    
    public static int howLong(int[] cakecounts){
        //cakecounts is an array with 0 in the 0th entry,
        //and n_i = number of diners with i cakes on their plate at the start.
        //Also the last entry should be nonzero.
        
        if(cakecounts.length < 4) return cakecounts.length - 1;
        int ret = Integer.MAX_VALUE;
        for(int maxsize = 2; maxsize < cakecounts.length; ++maxsize){
            int[] cakes = Arrays.copyOf(cakecounts, cakecounts.length);
            int numspec = 0;
            int maxstack = cakecounts.length-1;
            while(maxstack > maxsize){
                while(cakes[maxstack] > 0){
                    cakes[maxstack]--;
                    cakes[maxstack-maxsize]++;
                    cakes[maxsize]++;
                    numspec++;
                }
                maxstack--;
            }
            ret = Math.min(ret, maxsize + numspec);
        }
        return ret;
    }
    
    
    
    public static void main(String[] args){
       
        try{
            Scanner sc = new Scanner(new FileInputStream(new File(filename)));
            int no_of_times = sc.nextInt();
            
            for(int i = 0; i < no_of_times; ++i){
                int D = sc.nextInt();
                int[] platenumbers = new int[D];
                int maxnumber = 0;
                for(int j = 0; j < D; ++j){
                    platenumbers[j] = sc.nextInt();
                    maxnumber = Math.max(maxnumber, platenumbers[j]);
                }
                
                int[] cakecounts = new int[maxnumber+1];
                for(int j = 0; j < D; ++j){
                    cakecounts[platenumbers[j]]++;
                }
                
                
                FileOutputStream fos = new FileOutputStream(output, true);
                fos.write(("Case #" + (i+1) + ": " + howLong(cakecounts) +  "\n").getBytes());
                fos.close();
                
                
            }
            sc.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    
    
    
    
}