import java.util.*;
import java.io.*;

public class Main{
    public static void main(String args[])throws IOException{
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            
            //?????
            String str = br.readLine();
            int input = Integer.parseInt(str);
              
            //????
            String cmd = br.readLine();
            
           /* //?????
            String cmd_array[] = new String[cmd.length()];
            for(int k=0; k < cmd.length(); k++ ){
               cmd_array[k] = String.valueOf(cmd.charAt(i));
            }*/

            
            //???????
            String[] pattern =  {"AA","AB","AX","AY",
                                 "BA","BB","BX","BY",
                                 "XA","XB","XX","XY",
                                 "YA","YB","YX","YY"};

           int ans = Integer.MAX_VALUE;

            //??????dp????????????????????????????
            //??????????
           for(int i=0; i < pattern.length; ++i){
               for(int j=i+1; j < pattern.length; ++j){
                
                  //dp????
                  //????????????
                  int[] dp = new int[cmd.length()];
             
                  //dp????????
                  //dp????????index?????????????
                  for(int g=0; g < cmd.length();++g){
                   dp[g] = g+1;
                  }


                 for(int t=1; t < dp.length; ++t){
                   for(int o=0; o <2; ++o){
                      if(cmd.regionMatches(t-1, o==0 ? pattern[i] : pattern[j], 0, 2)){
                         dp[t] = Math.min(dp[t], 1+(0 <= t-2 && t-2 < dp.length ? dp[t-2] : 0));
                      }else{
                         dp[t] = Math.min(dp[t], 1+(0 <= t-1 && t-1 < dp.length ? dp[t-1] : 0));
                      }
                   }
                 }
                 ans = Math.min(ans, dp[dp.length - 1]);
                  
               }
           }
             System.out.println(ans);
        }
    }
}