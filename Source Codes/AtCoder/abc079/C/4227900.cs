using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
  //static List<string> list;
	static void Main(string[] args)
	{
		// ??????
        string input = Console.ReadLine();

        int a = int.Parse(input[0].ToString());
        int b = int.Parse(input[1].ToString());
        int c = int.Parse(input[2].ToString());
        int d = int.Parse(input[3].ToString());

        // a+b+c+d
        if(a+b+c+d == 7)
          Console.WriteLine(a + "+" + b + "+" + c + "+" + d + "=7");
        else if(a+b+c-d == 7)
          Console.WriteLine(a + "+" + b + "+" + c + "-" + d + "=7");
        else if(a+b-c+d == 7)
          Console.WriteLine(a + "+" + b + "-" + c + "+" + d + "=7");
        else if(a+b-c-d == 7)
          Console.WriteLine(a + "+" + b + "-" + c + "-" + d + "=7");
        else if(a-b+c+d == 7)
          Console.WriteLine(a + "-" + b + "+" + c + "+" + d + "=7");
        else if(a-b+c-d == 7)
          Console.WriteLine(a + "-" + b + "+" + c + "-" + d + "=7");
        else if(a-b-c+d == 7)
          Console.WriteLine(a + "-" + b + "-" + c + "+" + d + "=7");
        else if(a-b-c-d == 7)
          Console.WriteLine(a + "-" + b + "-" + c + "-" + d + "=7");


    // ??
        //Console.WriteLine(sum + "");
    }
		class myClass{ //?????
			public int ID {set; get;}
			public long Point {set; get;}
		}

    static private long Calculation(string input, int bin)
    {
      // ???i? 000????????????????
      // 101??????? + ? ? + ? ????input????????????????
      if(bin==0)
      {
        return long.Parse(input);
      }

      long sum = 0;
      string str = "";
      //for(int i=0; i<input.Length-1; i++)
      int i=0;
      while(bin>0)
      {
        int plus = bin%2;
        bin = bin/2;
        //Console.WriteLine("bin " + bin + " plus " + plus);
        if(plus == 1)
        {
          // input?????i+1????????sum????
          str += long.Parse(input.Substring(input.Length-i-1)) + " + (input:" + input.Substring(0, input.Length-i-1) + ")";
          sum += long.Parse(input.Substring(input.Length-i-1));
          input = input.Substring(0, input.Length-i-1);
          i=0;
        }else
        {
          i++;
        }
      }
      str += input;
      //Console.WriteLine(str);
      sum += long.Parse(input);

      return sum;
    }

}