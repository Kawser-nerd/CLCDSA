using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime dt1 = DateTime.Now;

            Program.Call();

            DateTime dt2 = DateTime.Now;
            TimeSpan ts2 = dt2.Subtract(dt1);
            Console.WriteLine("time: {0} ms", ts2.TotalMilliseconds);
        }

        static void Call()
        {
            MyProblem mp = new MyProblem();
            mp.run();
        }
    }

    class MyProblem
    {
        public class Event : System.IComparable
        {
            public Trip trip;
            public int time;
            public bool isStart;

            #region IComparable Members

            public int CompareTo(object obj)
            {
                int t = this.time - ((Event)obj).time;
                if (t == 0)
                {
                    if (this.isStart && !((Event)obj).isStart)
                    {
                        t = 1;
                    }
                    else if (!this.isStart && ((Event)obj).isStart)
                    {
                        t = -1;
                    }
                }
                return t;
            }

            #endregion
        }

        public class Trip: System.IComparable
        {
            public int start;
            public int end;
            public bool isFromA;

            #region IComparable Members

            public int CompareTo(object obj)
            {
                return this.start - ((Trip)obj).start;
            }

            #endregion
        }
        public void run()
        {
            string infile_name = @"F:\!!!20080705\GoogleCodeJam\Program2.0\GCodeJam\1-B-Train Timetable\B-large.in.txt";

            StreamReader sr = new StreamReader(infile_name);
            string line;
            line = sr.ReadLine();
            int N = Convert.ToInt32(line);
            int[] min_train_A = new int[N];
            int[] min_train_B = new int[N];
            for (int i = 0; i < N; i++)
            {
                line = sr.ReadLine();
                int T = Convert.ToInt32(line);
                line = sr.ReadLine();
                string[] ss = line.Trim().Split(' ');
                int NA = Convert.ToInt32(ss[0]);
                int NB = Convert.ToInt32(ss[1]);
                Trip[] trips = new Trip[NA + NB];
                Event[] events = new Event[trips.Length * 2];
                for (int j = 0; j < NA + NB; j++)
                {
                    line = sr.ReadLine();
                    ss = line.Trim().Split(' ');
                    trips[j] = new Trip();
                    trips[j].start = Convert.ToInt32(ss[0].Substring(0, 2)) * 60 + Convert.ToInt32(ss[0].Substring(3, 2));
                    trips[j].end = Convert.ToInt32(ss[1].Substring(0, 2)) * 60 + Convert.ToInt32(ss[1].Substring(3, 2));
                    trips[j].end += T;
                    if (j < NA)
                        trips[j].isFromA = true;
                    else
                        trips[j].isFromA = false;

                    events[j * 2] = new Event();
                    events[j * 2].time = trips[j].start;
                    events[j * 2].trip = trips[j];
                    events[j * 2].isStart = true;
                    events[j * 2 + 1] = new Event();
                    events[j * 2 + 1].time = trips[j].end;
                    events[j * 2 + 1].trip = trips[j];
                    events[j * 2 + 1].isStart = false;
                }

                Array.Sort(events);
                int A_train = 0;
                int B_train = 0;
                int A_train_start = 0;
                int B_train_start = 0;
                for (int j = 0; j < events.Length; j++)
                {
                    Event e = events[j];
                    if (e.isStart)
                    {
                        if (e.trip.isFromA)
                        {
                            if (A_train == 0)
                            {
                                A_train++;
                                A_train_start++;
                            }
                            A_train--;
                        }
                        else
                        {
                            if (B_train == 0)
                            {
                                B_train++;
                                B_train_start++;
                            }
                            B_train--;
                        }
                    }
                    else
                    {
                        if (e.trip.isFromA)
                        {
                            B_train++;
                        }
                        else
                        {
                            A_train++;
                        }
                    }
                }
                min_train_A[i] = A_train_start;
                min_train_B[i] = B_train_start;
            }

            sr.Close();

            /************************************************/



            /************************************************/

            string outfile_name = @"F:\!!!20080705\GoogleCodeJam\Program2.0\GCodeJam\1-B-Train Timetable\B-large.out.txt";

            StreamWriter sw = new StreamWriter(outfile_name);
            for (int i = 0; i < N; i++)
            {
                sw.WriteLine("Case #{0}: {1} {2}", i + 1, min_train_A[i], min_train_B[i]);
            }
            sw.Flush();
            sw.Close();
        }
    }
}


