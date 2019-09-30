using System;
class Program
{
	static void Main()
	{
	int a = int.Parse(Console.ReadLine());//int.Parse???????????
    string[] stringPlus = new string[a];
      for(int i = 0; i < a; i++)
	stringPlus[i] = Console.ReadLine();//Split???????????????????
      int b = int.Parse(Console.ReadLine());//int.Parse???????????
    string[] stringMinus = new string[b];
      for(int i = 0; i < b; i++)
	stringMinus[i] = Console.ReadLine();
      
      int maxPoint = 0;
      int point = 0;
      
      for(int i = 0; i < a; i++)
      {
        point = 0;
        for(int j = 0; j < a; j++)
        {
          if(stringPlus[i] == stringPlus[j])point++;
        }
        for(int j = 0; j < b; j++)
        {
          if(stringPlus[i] == stringMinus[j])point--;
        }
        if(point > maxPoint)maxPoint = point;
      }

	//??
	Console.WriteLine(maxPoint);//WriteLine?Write?????????????
	}
}