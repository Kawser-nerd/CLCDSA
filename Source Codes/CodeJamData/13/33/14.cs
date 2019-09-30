using System;
using System.IO;
using System.Collections;
using System.Linq;
using System.Collections.Generic;


namespace GoogleJam
{
	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	class ClassProblemSolverQB
	{

		[STAThread]
		static void Main(string[] args)
		{
			string fileName = "b-small";
			if (File.Exists(fileName + ".in"))
				ClassProblemSolverQB.ProcessFile(fileName);
			fileName = "b-large";
			if (File.Exists(fileName + ".in"))
				ClassProblemSolverQB.ProcessFile(fileName);

			
		}

		public static void ProcessFile(string fileName)
		{
			FileStream fileStreamWriter = new FileStream(fileName + ".out",FileMode.Create,FileAccess.Write);
			StreamWriter writer = new StreamWriter(fileStreamWriter);
			FileStream fileStreamReader = new FileStream(fileName + ".in",FileMode.Open,FileAccess.Read);
			StreamReader reader = new StreamReader(fileStreamReader);
			try
			{
				string s = reader.ReadLine();
				int numberOfTests = Convert.ToInt32(s);
				int currentTest = 0;
				while ((s = reader.ReadLine()) != null)
				{					
					currentTest++;
					if (currentTest > numberOfTests) 
						break;
                    writer.WriteLine("Case #{0}: {1}", currentTest, calc(parse(s,reader)));
				}

			}
			finally
			{
				reader.Close();
				fileStreamReader.Close();
				writer.Close();
				fileStreamWriter.Close();
			}

		}

        class Tribe
        {
            public int id;
            public int d;
            public int n;
            public int w, e;
            public int s;
            public int dd, dp, ds;
            public int i;

            public void Attack()
            {
                s += ds;
                w += dp;
                e += dp;
                i++;
                if (i >= n)
                    d = int.MaxValue;
                else
                    d += dd;
            }
        }
        class ProblemParams
        {
            public Tribe[] Tribes;
        }

        static Tribe[] getAttack(Tribe[] tribes)
        {
            var r = new List<Tribe>();
            int m = 6760600;
            foreach (var t in tribes)
            {
                int d = t.d;
                if (m > d)
                {
                    m = d;
                    r.Clear();
                    r.Add(t);
                }
                else if (m == d)
                {
                    r.Add(t);
                }
            }
            return r.ToArray();
        }

        static int calc(ProblemParams param)
        {
            var wall = new int[500];
            int result = 0;

            do
            {
                var tribes = getAttack(param.Tribes);
                if (tribes.Length == 0)
                    break;
                
                foreach (var t in tribes)
                {
                    bool isSuccess = false;

                    int kw = t.w * 2 + 200;
                    int ke = t.e * 2 + 200;
                    for (int k = kw; k <= ke; k++)
                        if (wall[k] < t.s)
                        {
                            // Console.WriteLine("Success:{0} on day {1} @ {2} s= {3} w={4}", t.id, t.d, k, t.s, wall[k]);
                            isSuccess = true;
                            result++;
                            break;
                        }
                    // if (!isSuccess) Console.WriteLine("Fail:{0} on day {1}", t.id, t.d);
                }
                foreach (var t in tribes)
                {
                    int kw = t.w * 2 + 200;
                    int ke = t.e * 2 + 200;
                    // Console.WriteLine("Raising wall: {0} from {1} to {2}", t.s, kw, ke);
                    for (int k = kw; k <= ke; k++)
                        wall[k] = wall[k] < t.s ? t.s : wall[k];
                    t.Attack();
                }
            } while (true);

            return result;
        }

        static ProblemParams parse(string s, StreamReader r)
        {
            ProblemParams result = new ProblemParams();
            string[] sp = s.Split(' ');
            int n = Convert.ToInt32(sp[0]);
            result.Tribes = new Tribe[n];
            for (int i = 0; i < n; i++)
            {
                s = r.ReadLine();
                Tribe t = new Tribe();
                string[] ssp = s.Split(' ');
                t.d = Convert.ToInt32(ssp[0]);
                t.n = Convert.ToInt32(ssp[1]);
                t.w = Convert.ToInt32(ssp[2]);
                t.e = Convert.ToInt32(ssp[3]);
                t.s = Convert.ToInt32(ssp[4]);
                t.dd = Convert.ToInt32(ssp[5]);
                t.dp = Convert.ToInt32(ssp[6]);
                t.ds = Convert.ToInt32(ssp[7]);
                t.id = i;
                result.Tribes[i] = t;
            }
            return result;                 
        }
    }
}
