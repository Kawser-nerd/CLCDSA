using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var p = new Program();
            p.Run();
        }

        private void Run()
        {
            //Assume data is on the desktop called input.txt
            var s = new StreamReader(@"C:\Users\richard\Desktop\input.txt");

            var caseNumber = 0;
            var sb = new StringBuilder();

            var start = DateTime.Now;

            //Ignore the first line - just tells us how many tests there are
            s.ReadLine();
            var sb1 = new StringBuilder();
            while(!s.EndOfStream)
            {
                caseNumber++;

                #region Main code bit

                var line = s.ReadLine().Split(' ');
                var D = double.Parse(line[0]);
                var N = int.Parse(line[1]);
                var A = int.Parse(line[2]);
                var T = new List<double>();
                var X = new List<double>();

                var isDone = false;
                for (var i = 0; i < N;i++ )
                {
                    var l = s.ReadLine().Split(' ');

                    if (!isDone)
                    {
                        var t = double.Parse(l[0]);
                        var x = double.Parse(l[1]);
                        if (x < D)
                        {
                            T.Add(t);
                            X.Add(x);
                        }
                        else if (Math.Abs(x - D) < 0.00000001)
                        {
                            T.Add(t);
                            X.Add(x);
                        }
                        else
                        {
                            if (t == 0)
                            {
                                T.Add(0);
                                X.Add(D);
                                isDone = true;
                            }
                            else
                            {
                                T.Add(T.Last() + (D - X.Last())*(t - T.Last())/(x - X.Last()));
                                X.Add(D);
                                isDone = true;
                            }
                        }
                    }
                }

                var accels = new List<double>();
                var l1 = s.ReadLine().Split(' ');
                for(var i = 0; i < A; i++)
                {
                    accels.Add(double.Parse(l1[i]));
                }

                
                sb.Append("Case #");
                sb.Append(caseNumber);
                sb.AppendLine(": ");

                foreach (var accel in accels)
                {
                    var currentSpeed = 0.0;
                    var currentPos = 0.0;
                    var totalTime = 0.0;
                    for (var i = 0; i < T.Count-1; i++ )
                    {
                        var distPossible = currentPos + currentSpeed * (T[i + 1] - T[i]) + 0.5 * accel * (T[i + 1] - T[i]) * (T[i + 1] - T[i]);

                            if (distPossible > X[i + 1])
                            {
                                if (X[i + 1] >= D)
                                {
                                    totalTime = T[i + 1];
                                    currentPos = D;
                                }
                                else
                                {
                                    //must throttle
                                    totalTime += T[i + 1] - T[i];
                                    var currentSpeedA = (2*(X[i + 1] - currentPos)/(T[i + 1]-T[i])) - currentSpeed;
                                    var currentSpeedB = Math.Sqrt(currentSpeed*currentSpeed + 2*accel*(X[i + 1] - currentPos));
                                    currentSpeed = Math.Max(currentSpeedA, currentSpeedB);
                                    currentPos = X[i + 1];
                                }
                            }
                            else
                            {
                                if (distPossible > D)
                                {
                                    totalTime+= Math.Sqrt(((currentSpeed * currentSpeed) / (accel * accel))
                                               + (2 * (D - currentPos)) / accel) - currentSpeed / accel;
                                    currentPos = D;
                                }
                                else
                                {
                                    totalTime += T[i + 1] - T[i];
                                    currentPos = distPossible;
                                    currentSpeed = currentSpeed + (T[i + 1]-T[i])*accel;
                                }
                            }
                        //}
                    }
                    if(currentPos<D)
                    {
                        totalTime += Math.Sqrt(((currentSpeed*currentSpeed)/(accel*accel))
                                               + (2*(D - currentPos))/accel) - currentSpeed/accel;
                    }
                    sb.AppendLine(Math.Round(totalTime,7).ToString());
                }


                //sb.AppendLine();
                
                #endregion
            }
            sb.AppendLine(sb1.ToString());

            //Write output file
            var sw = new StreamWriter(@"C:\Users\richard\Desktop\output.txt", false);
            sw.Write(sb.ToString());
            sw.Flush();
        }
    }
}
