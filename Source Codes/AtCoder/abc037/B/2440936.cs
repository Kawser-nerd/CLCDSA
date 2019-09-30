using System;
public class Hello{
    public static void Main(){
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int Q = int.Parse(input[1]);
        
        int[] nums = new int[N];
        for(int n = 0;n < N;n++){
            nums[n] = 0;
        }
        
        for(int i = 0;i < Q;i++){
            int[] temp = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
            int l = temp[0];
            int r = temp[1];
            int t = temp[2];
            for(int j = l - 1;j < r;j++){
                nums[j] = t;
            }
        }
        
        foreach(int ans in nums){
            Console.WriteLine(ans);
        }
    }
}