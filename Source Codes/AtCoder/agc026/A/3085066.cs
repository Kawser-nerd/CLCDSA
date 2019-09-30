using System;
class MainClass{
    public static void Main(string[] args){
        int cnt = 0;
        int num =int.Parse(Console.ReadLine());
        string[] input = Console.ReadLine().Split(' ');
        for (int i = 1; i < num; i++){
            if (int.Parse(input[i]) == int.Parse(input[i - 1])){
                cnt++; i++;
            }
        }
        Console.WriteLine(cnt);
    }
}