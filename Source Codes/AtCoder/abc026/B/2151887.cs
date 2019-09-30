using System;
public class Hello{
    public static void Main(){
        int N = int.Parse(Console.ReadLine());
        double[] circles = new double[N];
        double ans = 0;
        for(int i = 0;i < N;i++){
            circles[i] = double.Parse(Console.ReadLine());
        }
        Array.Sort(circles);
        Array.Reverse(circles);
        for(int i = 0;i < N;i++){
            if(i % 2 == 0){
                ans += Math.PI * Math.Pow(circles[i],2);
            }else{
                ans -= Math.PI * Math.Pow(circles[i],2); 
            }
        }
        Console.WriteLine(ans);
    }
}