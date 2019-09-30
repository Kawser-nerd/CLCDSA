using System;
public class Hello{
    static int Sum(int[] a){
        int sum = 0;
        for(int i = 0; i < a.Length;i++){
            sum += a[i];
        }
        return sum;
    } 
    public static void Main(){
        int N = int.Parse(Console.ReadLine());
        string[] cityName = new string[N];
        int[] pop = new int[N];
        
        for(int i = 0;i < N;i++){
            string[] input = Console.ReadLine().Split(' ');
            cityName[i] = input[0];
            pop[i] = int.Parse(input[1]);
        }
        int sum = Sum(pop);
        
        for(int j = 0;j < N;j++){
            if(pop[j] > sum / 2){
                Console.WriteLine(cityName[j]);
                return;
            }
        }
        Console.WriteLine("atcoder");
    }
}