using System;

public class Class1
{
    static void Main(string[] args)
    {
        var Class1 = new Class1();
    }

	public Class1()
	{
        string[] Input = Console.ReadLine().Split(' ');
        int[] nums = new int[3];
        int Total = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            nums[i] = int.Parse(Input[i]);
            Total += nums[i];
        }


        for (int i = 0; i < 3; i++)
        {
            if (Total - nums[i] == nums[i])
            {
                Console.WriteLine("Yes");
                break;
            }
            else if (i == 2)
            {
                Console.WriteLine("No");
            }
        }

	}
}