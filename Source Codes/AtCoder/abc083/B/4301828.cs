using System;

namespace System{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int A = int.Parse(s[1]);
            int B = int.Parse(s[2]);
            int sum = 0;
            for(int i=1; i<=N; i++){
                int digsum = 0;
                int num = i;
                while(num != 0){
                    digsum += num%10;
                    num /= 10;
                }
                if(digsum >= A && digsum <= B){
                    sum+=i;
                }
            }
            Console.WriteLine(sum);
        }
    }
}