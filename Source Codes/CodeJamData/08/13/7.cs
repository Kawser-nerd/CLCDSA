using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Numbers
{
    StreamWriter writer = new StreamWriter("A-small.out");
    List<string> nums = new List<string>();

    public void Calc()
    {
        nums.Add(string.Empty);
        nums.Add(string.Empty);

        nums.Add("027");
        nums.Add("143");
        nums.Add("751");
        nums.Add("935");
        nums.Add("607");
        nums.Add("903");
        nums.Add("991");
        nums.Add("335");
        nums.Add("047");
        nums.Add("943");
        nums.Add("471");
        nums.Add("055");
        nums.Add("447");
        nums.Add("463");
        nums.Add("991");
        nums.Add("095");
        nums.Add("607");
        nums.Add("263");
        nums.Add("151"); //20
        nums.Add("855");
        nums.Add("527");
        nums.Add("743");
        nums.Add("351");
        nums.Add("135");
        nums.Add("407");
        nums.Add("903");
        nums.Add("791");

        nums.Add("135");
        nums.Add("647");

        using (StreamReader sr = File.OpenText("A-small.in"))
        {
            long numCases = Convert.ToInt32(sr.ReadLine());
            for (int i = 0; i < numCases; i++)
            {
                int n = Convert.ToInt32(sr.ReadLine());
                writer.WriteLine(string.Format("Case #{0}: {1}", i+1, nums[n]));
            }
        }

        writer.Close();
    }
}
