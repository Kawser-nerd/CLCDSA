using System;
using System.Linq;

public class Hello{
    public static void Main(){
        int[] n = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        int[] box = new int[n[0]];
        for(int i = 0;i < n[1];i++){
            int[] num = Console.ReadLine().Split(' ').Select(b => int.Parse(b)).ToArray();
            for(int j = num[0] - 1;j < num[1];j++){
                box[j] = num[2];
            }
        }
        for(int i = 0;i < n[0];i++){
            Console.WriteLine(box[i]);
        }
    }
}