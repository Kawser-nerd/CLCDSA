using System;
class Program
{
	static void Main(string[] args)
	{
		string date = Console.ReadLine();
		
        DateTime boundary = DateTime.Parse("2019/04/30");

        DateTime date2 = DateTime.Parse(date);

        if(boundary >= date2)
        {
            Console.WriteLine("Heisei");
        }
        else
        {
            Console.WriteLine("TBD");
        }

		//Console.WriteLine((a+b+c) + " " + s);
	}
}