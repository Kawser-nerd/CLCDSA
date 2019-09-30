using System;
class Program
{
    static void Main(string[] args)
    {
        int m,VV;
        m = int.Parse(Console.ReadLine());
        if(m < 100)
        {
            Console.WriteLine("{0}{0}",0,0);
        }else if(m <= 5000)
        {
            if(m < 1000)
            {
                Console.WriteLine("{0}{1}",0,m/100);
            }else{
                Console.WriteLine("{0}",m/100);
            }
        }else if(m <= 30000)
        {
            Console.WriteLine("{0}",m/1000 + 50);
        }else if(m <= 70000)
        {
            Console.WriteLine("{0}",(m/1000 - 30)/5 + 80);
        }else
        {
            Console.WriteLine("{0}",89);
        }
    }
}