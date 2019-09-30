using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {                   
        class Step
        {
            public int sorted;
            public int[] input;

            public override string ToString()
            {
                return string.Format("Sorted: {0}, Input: {1}", sorted, String.Join(",", input));
            }
        }

        static Step findUnsortedGroup(int[] input)
        {
            var sortedInput = new int[input.Length];
            input.CopyTo(sortedInput, 0);
            Array.Sort(sortedInput);
            int st;
            for(st = 0;st<input.Length;st++)
            {
                if (sortedInput[st] != input[st]) break;                
            }
            if (st == input.Length) return new Step { input =  input, sorted =  0 };
            int frompos;
            int sorted = 1;
            do
            {
                var needel = sortedInput[st];                
                frompos = pos(input, needel);
                if (frompos != st)
                {
                    var oldel = input[st];
                    input[st] = needel;
                    input[frompos] = oldel;
                    st = frompos; 
                    sorted++;
                }
                else break;                

            } while (true);
            return new Step {input = input, sorted = sorted};
        }
        
        static void Main(string[] args)
        {            
            TextReader tr = new StreamReader(args[0]);
            var cases = int.Parse(tr.ReadLine());
            for(int caseN = 0;caseN<cases;caseN++)
            {
                Console.Write("Case #"+(caseN+1)+": ");
                tr.ReadLine();
                var input = (from v in tr.ReadLine().Split(' ') select int.Parse(v)).ToArray();
                Step stt = new Step() { input = input };
                int result =0;
                do
                {
                    stt = findUnsortedGroup(stt.input);                    
                    result += stt.sorted;
                } while (stt.sorted > 0); 
                //var result =  
                Console.WriteLine(result);
            }
            Console.ReadKey();

        }

        private static int pos(int[] ints, int val)
        {
            for (int i = 0; i < ints.Length; i++)
            {
                if (ints[i] == val) return i;
            }
            throw new ArgumentException("value "+val +" was not found");
        }
    }
}

