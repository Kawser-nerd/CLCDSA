using System;

class Program
{
    static void Main(string[] args)
    {
        int A = int.Parse(Console.ReadLine());
        int B = int.Parse(Console.ReadLine());
        int C = int.Parse(Console.ReadLine());
        int X = int.Parse(Console.ReadLine());
        int count = 0;
        for(int i=0; i<=A; i++){
            if(X == 500*i){
                count++;
                break;
            } 
            for(int j=0; j<=B; j++){
                if(X == 500*i + 100*j){
                    count++;
                    break;
                }
                for(int k=0; k<=C; k++){
                    if(X == 500*i + 100*j + 50*k){
                        count++;
                        break;
                    }
                }
            }
        }
        Console.WriteLine(count);
    }
}