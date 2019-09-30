using System;
using System.Linq;

public class Hello{
    public static void Main(){
        int a = int.Parse(Console.ReadLine());
        int ans = 1000000;
        int box = 0;
        for(int i = 1;i <= Math.Pow((double)a,0.5);i++){
            box = i * (a/i);
            box = a - box;
            box += Math.Abs(i - (a/i));
            //Console.WriteLine(i + " x " + (a/i) + " = " +i * (a/i));
            //Console.WriteLine( Math.Abs(i - (a/i)));
            if(box < ans)ans = box;
        }
        Console.WriteLine(ans);
    }
}