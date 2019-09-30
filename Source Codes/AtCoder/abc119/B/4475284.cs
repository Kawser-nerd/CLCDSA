using System;


namespace _119_ABC
{
    class Program01
    {
        static void Main(string[] args)
        {

            int N = int.Parse(Console.ReadLine());
            double Answer = 0.0;

            for(int i = 0; i < N; i++)
            {
                string[] Input = Console.ReadLine().Split(' ');
                double X = double.Parse(Input[0]);
                string U = Input[1];

                if(U == "JPY")
                {
                    Answer += X;
                }
                else
                {
                    Answer += X * 380000.0;
                }
            }

            Console.WriteLine(Answer);

        }
    }
}