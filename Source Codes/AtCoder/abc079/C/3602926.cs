using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string s = Console.ReadLine();
    int a = s[0] - '0';
    int b = s[1] - '0';
    int c = s[2] - '0';
    int d = s[3] - '0';
    string answer = "";

      if(a+b+c+d == 7)
      {
        answer=a.ToString()+"+"+b.ToString()+"+"+c.ToString()+"+"+d.ToString()+"=7";
      }
      if(a+b+c-d == 7)
      {
        answer=a.ToString()+"+"+b.ToString()+"+"+c.ToString()+"-"+d.ToString()+"=7";
      }
      if(a+b-c+d == 7)
      {
        answer=a.ToString()+"+"+b.ToString()+"-"+c.ToString()+"+"+d.ToString()+"=7";
      }
      if(a+b-c-d == 7)
      {
        answer=a.ToString()+"+"+b.ToString()+"-"+c.ToString()+"-"+d.ToString()+"=7";
      }
      if(a-b+c+d == 7)
      {
        answer=a.ToString()+"-"+b.ToString()+"+"+c.ToString()+"+"+d.ToString()+"=7";
      }
      if(a-b+c-d == 7)
      {
        answer=a.ToString()+"-"+b.ToString()+"+"+c.ToString()+"-"+d.ToString()+"=7";
      }
      if(a-b-c+d == 7)
      {
        answer=a.ToString()+"-"+b.ToString()+"-"+c.ToString()+"+"+d.ToString()+"=7";
      }
      if(a-b-c-d == 7)
      {
        answer=a.ToString()+"-"+b.ToString()+"-"+c.ToString()+"-"+d.ToString()+"=7";
      }
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}