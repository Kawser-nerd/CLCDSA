using System;
class Program
{
	static void Main()
	{
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	int a = int.Parse(input[0]);
	int b = int.Parse(input[1]);
    int c = int.Parse(input[2]);
    int x = int.Parse(input[3]);
    int y = int.Parse(input[4]);
      
      long cost = 0;
      long minCost = 0;
    if(x>=y)
    {
       for(int i = 0; i <= x; i++)//A???????
       {
         if(y-i>0) cost = a*(x-i) + c*2*i + b*(y-i);
         else cost = a*(x-i) + c*2*i;
         if(cost < minCost || minCost == 0) minCost = cost;
       }
    }
    else
   	{
      
      for(int i = 0; i <= y; i++)//B???????
       {
        if(x-i>0) cost = b*(y-i) + c*2*i + a*(x-i);
        else cost = b*(y-i) + c*2*i;
         if(cost < minCost || minCost == 0) minCost = cost;
       }
    }

     	 Console.WriteLine(minCost);
	}
}