using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int kazu = int.Parse(ReadLine());
        int[] ans = new int[2];
        ans[1] = 1;
        for(int i=1;i<=kazu;i++){
            int k = i;
            int count = 0;
            for(int j=0;j<10;j++){
                if(k%2==0){
                    k/=2;
                    count++;
                }else{
                    break;
                }
            }
            if(count>ans[0]){
                ans[0]=count;
                ans[1]=i;
            }
        }
        WriteLine("{0}",ans[1]);
    }
}