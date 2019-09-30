using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace magictrick
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader fin = new StreamReader("C:\\Users\\yzhao\\Downloads\\A-small-attempt1.in");
            StreamWriter fout = new StreamWriter("out.txt");
            int t = int.Parse(fin.ReadLine());
            for (int casecount = 1; casecount <= t; casecount++)
            {
                int firstrow = int.Parse(fin.ReadLine());
                for (int i = 1; i < firstrow; i++)
                    fin.ReadLine();
                int[] first = new int[4];
                string[] firstlist = fin.ReadLine().Split(' ');
                for (int i = 0; i < 4; i++)
                    first[i] = int.Parse(firstlist[i]);
                for (int i = firstrow + 1; i <= 4; i++)
                    fin.ReadLine();
                int secondrow = int.Parse(fin.ReadLine());
                for (int i = 1; i < secondrow; i++)
                    fin.ReadLine();
                int[] second = new int[4];
                string[] secondlist = fin.ReadLine().Split(' ');
                for (int i = 0; i < 4; i++)
                    second[i] = int.Parse(secondlist[i]);
                for (int i = secondrow + 1; i <= 4; i++)
                    fin.ReadLine();
                int same = 0;
                int samecount = 0;
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        if (first[i] == second[j])
                        {
                            same = first[i];
                            samecount++;
                        }
                if (samecount == 1)
                    fout.WriteLine("Case #"+ casecount + ": " + same);
                else if (samecount > 1)
                    fout.WriteLine("Case #" + casecount + ": Bad magician!");
                else
                {
                    fout.WriteLine("Case #" + casecount + ": Volunteer cheated!");
                }
            }
            fin.Close();
            fout.Close();
        }
    }
}
