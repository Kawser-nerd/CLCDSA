using System;

namespace Beginner023B
{
    class Program
    {
        static void Main(string[] args)
        {
            var accessoryLength = int.Parse(Console.ReadLine());
            var exampleAccessory = Console.ReadLine();

            var accessory = string.Empty;

            for (int numberOfProcedure = 0; accessory.Length < accessoryLength; numberOfProcedure++)
            {
                accessory = accessory.MakeAccessory(numberOfProcedure);
                if (accessory.Equals(exampleAccessory))
                {
                    Console.WriteLine(numberOfProcedure);
                    return;
                }
            }

            Console.WriteLine(-1);
        }
    }

    public static class Extends
    {
        public static string MakeAccessory(this string accessory, int numberOfProcedure)
        {
            if (numberOfProcedure == 0)
            {
                return "b";
            }

            switch (numberOfProcedure % 3)
            {
                case 0:
                    return "b" + accessory + "b";
                case 1:
                    return "a" + accessory + "c";
                case 2:
                    return "c" + accessory + "a";
                default:
                    throw new Exception("WTF!!!");
            }
        }
    }
}