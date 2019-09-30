using System;
class Program
{
	static void Main(string[] args)
	{
            var input = Console.ReadLine();

            var date = DateTime.Parse(input);

            while (true)
            {
                var Y = date.Year;
                var M = date.Month;
                var D = date.Day;

                var ym = (decimal)Y / M;
                if (ym == Math.Floor(ym))
                {
                    var ymd = ym / D;
                    if (ymd == Math.Floor(ymd))
                    {
                        Console.WriteLine(string.Format("{0:0000}/{1:00}/{2:00}", Y, M, D));
                        break;
                    }
                    date = date.AddDays(1);
                }
                else
                {
                    date = new DateTime(Y, M, 1);
                    date = date.AddMonths(1);
                }
            }

	}
}