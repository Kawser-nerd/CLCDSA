using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> lResult = new List<string>();
            int passlength;
            string inValue = string.Empty;
            string passValue = string.Empty;
            
            passValue = Console.ReadLine();
            inValue = Console.ReadLine();

            if (!int.TryParse(inValue, out passlength))
            {
                passlength = 0;
            }

            if (passlength == 0 || passlength > passValue.Length)
            {
                Console.WriteLine("0");
                return;
            }

            string checkvalue = string.Empty;
            
            foreach (char c in passValue)
            {
                if (passlength == checkvalue.Length)
                {
                    if (!lResult.Contains(checkvalue))
                    {
                        lResult.Add(checkvalue);
                    }
                    checkvalue = checkvalue.Substring(1);
                }
                checkvalue += c.ToString();

            }

            if (passlength == checkvalue.Length)
            {
                if (!lResult.Contains(checkvalue))
                {
                    lResult.Add(checkvalue);
                }
            }

            Console.WriteLine(lResult.Count().ToString());
        }
    }
}