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
      
      long minCost = 0;

       for(int i = 0; i <= x+y; i++)//AB????????????
       {
         long cost = 0;
         cost += 2*c*i;//AB?????
         if(x-i>0) cost += a*(x-i);//A???????
         if(y-i>0) cost += b*(y-i);//A???????
         if(cost < minCost || minCost == 0) minCost = cost;//?????????
       }
      
     	 Console.WriteLine(minCost);
      
	}
}