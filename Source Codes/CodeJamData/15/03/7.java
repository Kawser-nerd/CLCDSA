import java.util.*;
import java.io.*;

public class Dijkstra{
    
    static final String filename = "C:/Users/Kevin/algs4/CodeJam/Dijkstra/C-large.in";
    static final String output = "largeoutputfinal.txt";
    
    //1, i, j, k, -1, -i, -j, -k
    
    public int[][] table;
    
    public Dijkstra(){
        table = new int[8][8];
        for(int i = 0; i < 8; ++i){
            table[0][i] = i;
            table[i][0] = i;
            table[4][i] = (i+4)%8;
            table[i][4] = (i+4)%8;
        }
        for(int i = 0; i < 8; ++i){
            if(i%4 == 0) continue;
            table[i][i] = 4;
            table[i][(i+4)%8] = 0;
        }
        table[1][2] = 3;
        table[2][3] = 1;
        table[3][1] = 2;
        table[2][1] = 7;
        table[3][2] = 5;
        table[1][3] = 6;
        
        for(int i = 1; i < 4; ++i){
            for(int j = 5; j < 8; ++j){
                table[i][j] = table[4][table[i][j-4]];
                table[j][i] = table[4][table[j-4][i]];
            }
        }
        
        for(int i = 5; i < 8; ++i){
            for(int j = 5; j < 8; ++j){
                table[i][j] = table[i-4][j-4];
            }
        }
    }
    
    
    
    public boolean Correct(int[] L, long X){
        int currblock = 0;
        int count = 0;
        int iprod = 0;
        int i = 0;
        outerloop:
        while(count < 5){
            for(; i < L.length; ++i){
                if(iprod == 1) break outerloop;
                iprod = table[iprod][L[i]];
            }
            ++currblock;
            i = 0;
            ++count;
        }
        
        if(count == 5) return false;
        count = 0;
        int jprod = 0;
        outerloop:
        while(count < 5){
            for(; i < L.length; ++i){
                if(jprod == 2) break outerloop;
                jprod = table[jprod][L[i]];
            }
            ++currblock;
            i = 0;
            ++count;
        }
        if(count == 5) return false;
        
        
        long rem_full_blocks = X - currblock - 1;
        if (rem_full_blocks < 0) return false;
        rem_full_blocks = rem_full_blocks%4;
        int blockprod = prodArray(L);
        int prod_rem_full = 0;
        for(int j = 0; j < rem_full_blocks; ++j){
            prod_rem_full = table[prod_rem_full][blockprod];
        }
        
        int prod_rem = table[prodArray(Arrays.copyOfRange(L, i, L.length))][prod_rem_full];
        
        return (prod_rem == 3);
        
    }
    
    
    public int prodArray(int[] inp){
        int ret = 0;
        for(int i = 0; i < inp.length; ++i){
            ret = table[ret][inp[i]];
        }
        return ret;
    }
    
    
    public static void main(String[] args){
      Dijkstra dijk = new Dijkstra();
      try{
            Scanner sc = new Scanner(new FileInputStream(new File(filename)));
            int no_of_times = sc.nextInt();
            
            for(int i = 0; i < no_of_times; ++i){
                int[] L = new int[sc.nextInt()];
                long X = sc.nextLong();
                sc.nextLine();
                String s = sc.nextLine();
                for(int j = 0; j < s.length(); ++j){
                    if(s.charAt(j) == 'i') L[j] = 1;
                    else if(s.charAt(j) == 'j') L[j] = 2;
                    else if(s.charAt(j) == 'k') L[j] = 3;
                }
                
                
                
                FileOutputStream fos = new FileOutputStream(output, true);
                fos.write(("Case #" + (i+1) + ": " + (dijk.Correct(L,X) ? "YES" : "NO") +  "\n").getBytes());
                fos.close();
                
                
            }
            sc.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
        
    }
    
    
    
    
    
    
}