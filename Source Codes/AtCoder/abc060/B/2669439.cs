using System;
public class Hello{
    public static void Main(){
        var input = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
        int A = input[0];
        int B = input[1];
        int C = input[2];
        
        var nums = new long[1000];
        nums[0] = 0;
        for(var i = 1;i < nums.Length;i++){
            nums[i] = i * A;
            if(nums[i] % B == C){
                Console.WriteLine("YES");
                return;
            }
        }
        Console.WriteLine("NO");
    }
}