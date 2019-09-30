using System;
public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ');
        var N = int.Parse(input[0]);
        var T = int.Parse(input[1]);
        
        int ans = 0;
        int[] nums = new int[N];
        for(var i = 0;i < N;i++){
            nums[i] = int.Parse(Console.ReadLine());
        }
        
        for(var j = 1;j < N;j++){
            if(nums[j] - nums[j - 1] >= T){
                ans += T;
            }else{
                ans += nums[j] - nums[j - 1];
            }
        }
        ans += T;   
        Console.WriteLine(ans);
    }
}