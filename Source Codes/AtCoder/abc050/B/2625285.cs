using System;
public class Hello{
    public static void Main(){
        int N = int.Parse(Console.ReadLine());
        int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
        int M = int.Parse(Console.ReadLine());
        
        for(var i = 0;i < M;i++){
            int ans = 0;
            
            string[] input = Console.ReadLine().Split(' ');
            int dn = int.Parse(input[0]);
            int time = int.Parse(input[1]);
            for(var j = 0;j < N;j++){
                if(j == dn - 1){
                    ans += time;
                }else{
                    ans += nums[j];
                }
            }
            Console.WriteLine(ans);
        }
        
    }
}