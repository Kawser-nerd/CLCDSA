using System;
public class Hello{
    public static void Main(){
        string[] s = Console.ReadLine().Split(' ');
        int N = int.Parse(s[0]);
        int K = int.Parse(s[1]);
        long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
        long ans = 0;
        long temp = 0;
        for(int i = 0;i < N;i++){
            if(i < K){
                temp += nums[i];
            }else{
                ans += temp;
                temp -= nums[i - K];
                temp += nums[i];
            }
        }
        ans += temp;
        Console.WriteLine(ans);
    }
}