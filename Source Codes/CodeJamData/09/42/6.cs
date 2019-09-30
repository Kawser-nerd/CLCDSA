using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GJ
{
    class CodeJam
    {
        static void Main(string[] args)
        {
            new Digging().Run("in.in", "out.out");
        }

        public static void WriteCase(StreamWriter output, int caseNum, string content)
        {
            Console.WriteLine("Case #" + caseNum.ToString() + ": " + content);
            output.WriteLine("Case #" + caseNum.ToString() + ": " + content);
        }
        public static int[] ReadLine(StreamReader input)
        {
            char[] split = { ' ' };
            string[] line = input.ReadLine().Split(split);
            int[] nums = new int[line.Length];
            for (int i = 0; i < nums.Length; i++)
                nums[i] = int.Parse(line[i]);
            return nums;
        }
    }
}
