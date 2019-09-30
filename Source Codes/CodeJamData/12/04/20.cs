using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem2011_1C_A
{
    class Program
    {
        static StreamReader streamReader;
        static StreamWriter streamWriter;

        static void processLine(Action<string> action)
        {
            action.Invoke(streamReader.ReadLine());
        }

        static void processLine(Action<IEnumerator<string>>[] actions)
        {
            processLine(() => { return streamReader.ReadLine().Split(' '); }, actions);
        }

        static void processLine(Func<string[]> splitFunc, Action<IEnumerator<string>>[] actions)
        {
            string[] parts = splitFunc.Invoke();
            IEnumerator<string> partsEnumerator = (IEnumerator<string>)parts.AsEnumerable<string>().GetEnumerator();
            partsEnumerator.Reset();
            foreach (Action<IEnumerator<string>> action in actions)
            {
                partsEnumerator.MoveNext();
                action.Invoke(partsEnumerator);
            }
        }

        static void Main(string[] args)
        {
            //Using fisrt arg as input file path
            FileStream inputFileStream = new FileStream(args[0], FileMode.Open);
            //Using second arg as output file path
            FileStream outputFileStream = new FileStream(args[1], FileMode.Create);

            //Stream Reader to read lines as strings
            streamReader = new StreamReader(inputFileStream);

            //Stream Writer to write strings as lines
            streamWriter = new StreamWriter(outputFileStream);

            //Reading amount of cases
            int nSamples = 0;
            processLine((s) => { nSamples = int.Parse(s); });

            //Process cases
            for (int i = 1; i <= nSamples; i++)
            {
                if (streamReader.EndOfStream) break;
                processCase(i);
            }
            streamWriter.Flush();
        }

        static public void processCase(int currentCaseNumber)
        {
            string caseResult = "";
            string debugString = "";
            int count = 0;
            int W = 0;
            int H = 0;
            int D = 0;
            //Reading case variables
            processLine(new Action<IEnumerator<string>>[]
            {
                (e) => H = int.Parse(e.Current),
                (e) => W = int.Parse(e.Current),
                (e) => D = int.Parse(e.Current)
            });

            string[] stringMap = new string[H];

            for (int i = 0; i < H; i++)
            {
                processLine((s) => stringMap[i] = s);
            }

            MirrorMap map = new MirrorMap(stringMap);
            map.unfoldReflections(D);
            count = map.countReflections(D);

            caseResult = ""+count;
            //Result
            streamWriter.WriteLine("Case #" + currentCaseNumber + ": " + caseResult + debugString);
        }
    }


    public class MirrorMap
    {
        public List<MirrorPlane> planes = new List<MirrorPlane>();
        public List<Player> players = new List<Player>();
        public MirrorMap unfoldMap;

        public MirrorMap() { }

        public MirrorMap(string[] stringMap)
        {
            for (int j = 0; j < stringMap.Length; j++)
            {
                for (int i = 0; i < stringMap[j].Length; i++)
                {
                    switch (stringMap[j][i])
                    {
                        case 'X' :
                            players.Add(new Player(i+0.5d, j+0.5d));
                        break;
                        case '#' :
                            if (j > 0) planes.Add(new MirrorPlane(i, j, i + 1, j));
                            if (i > 0) planes.Add(new MirrorPlane(i, j, i, j + 1));
                            if (j < stringMap.Length - 1) planes.Add(new MirrorPlane(i, j + 1, i + 1, j + 1));
                            if (i < stringMap[j].Length - 1) planes.Add(new MirrorPlane(i + 1, j, i + 1, j + 1));
                        break;
                    }
                }
            }
            unfoldMap = new MirrorMap();
        }

        public void joinPlanes()
        {
            bool unjoinable = false;
            while (!unjoinable)
            {
                unjoinable = true;
                for (int i = 0; i < planes.Count; i++)
                {
                    for (int j = i + 1; j < planes.Count; j++)
                    {
                        if (
                            (planes[i].X1 == planes[j].X1) &&
                            (planes[i].Y1 == planes[j].Y1) &&
                            (planes[i].X2 == planes[j].X2) &&
                            (planes[i].Y2 == planes[j].Y2)
                            )
                        {
                            planes.RemoveAt(j);
                            planes.RemoveAt(i);
                            unjoinable = false;
                            break;
                        }
                    }
                    if (!unjoinable) break;
                }
                if (unjoinable)
                {
                    for (int i = 0; i < planes.Count; i++)
                    {
                        for (int j = i + 1; j < planes.Count; j++)
                        {
                            if (
                                    (
                                        planes[i].isHorizontal() == planes[j].isHorizontal()
                                    ) &&
                                    (
                                        (
                                            planes[i].isHorizontal() &&
                                            planes[i].Y1 == planes[j].Y1 &&
                                            planes[i].X1 <= planes[j].X2 &&
                                            planes[i].X2 >= planes[j].X1
                                        ) ||
                                        (
                                            !planes[i].isHorizontal() &&
                                            planes[i].X1 == planes[j].X1 &&
                                            planes[i].Y1 <= planes[j].Y2 &&
                                            planes[i].Y2 >= planes[j].Y1
                                        )
                                    )
                                )
                            {
                                planes.Add(MirrorPlane.join(planes[i], planes[j]));
                                planes.RemoveAt(j);
                                planes.RemoveAt(i);
                                unjoinable = false;
                                break;
                            }
                        }
                        if (!unjoinable) break;
                    }
                }
            }
        }

        public void unfoldReflections(int distance)
        {
            unfoldMap.players.Add(players[0]);
            unfoldMap.planes.AddRange(planes);
            unfoldMap.unfoldReflections(players[0].X, players[0].Y, distance);
        }

        public void unfoldReflections(double X, double Y, int distance)
        {
            bool nearPlanes = true;
            while (nearPlanes)
            {
                joinPlanes();
                nearPlanes = false;
                bool farPlanes = true;
                while (farPlanes)
                {
                    farPlanes = false;
                    for (int i = 0; i < planes.Count; i++)
                    {
                        if (!((planes[i].isHorizontal() && Math.Abs(planes[i].Y1 - Y) < distance) ||
                           (!planes[i].isHorizontal() && Math.Abs(planes[i].X1 - X) < distance)))
                        {
                            planes.RemoveAt(i);
                            farPlanes = true;
                            break;
                        }
                    }
                }
                if (planes.Count > 0)
                {
                    unfoldByPlaneAt(0);
                    nearPlanes = true;
                }
            }
        }

        public void unfoldByPlaneAt(int pos)
        {
            MirrorPlane p = planes[pos];
            planes.RemoveAt(pos);

            int nPlanes = planes.Count;
            for (int i = 0; i < nPlanes; i++)
            {
                planes.Add(planes[i].flipBy(p));
            }

            int nPlayers = players.Count;
            for (int i = 0; i < nPlayers; i++)
            {
                Player newPlayer = new Player(players[i].X, players[i].Y);

                newPlayer.flipBy(p);

                /*foreach (MirrorPlane mp in players[i].crosedPlanes)
                {
                    newPlayer.crosedPlanes.Add(mp.flipBy(p));
                }*/
                newPlayer.crosedPlanes.Add(p);

                players.Add(newPlayer);
            }
        }

        public int countReflections(int distance)
        {
            int count = 0;
            foreach (Player p in unfoldMap.players)
            {
                if (p.visibleFrom(players[0].X, players[0].Y, distance, unfoldMap.players)) count++; 
            }
            return count;
        }
    }

    public class MirrorPlane
    {
        public double X1;
        public double Y1;
        public double X2;
        public double Y2;

        public MirrorPlane(double X1, double Y1, double X2, double Y2)
        {
            this.X1 = Math.Min(X1, X2);
            this.Y1 = Math.Min(Y1, Y2);
            this.X2 = Math.Max(X1, X2);
            this.Y2 = Math.Max(Y1, Y2);
        }

        public bool isHorizontal()
        {
            return (this.Y1 == this.Y2);
        }

        public bool crossedBy(double X1, double Y1, double X2, double Y2)
        {
            if (!isHorizontal())
            {
                if (X1 == X2) return false;
                double Y = Y1 + (Y2 - Y1) * (this.X1 - X1) / (X2 - X1);
                return (Y > Math.Min(this.Y1, this.Y2)) && (Y < Math.Max(this.Y1, this.Y2));
            }
            else
            {
                if (Y1 == Y2) return false;
                double X = X1 + (X2 - X1) * (this.Y1 - Y1) / (Y2 - Y1);
                return (X > Math.Min(this.X1, this.X2)) && (X < Math.Max(this.X1, this.X2));
            }
        }

        public static MirrorPlane join(MirrorPlane mp1, MirrorPlane mp2)
        {
            return new MirrorPlane(Math.Min(mp1.X1, mp2.X1),Math.Min(mp1.Y1, mp2.Y1), Math.Max(mp1.X2, mp2.X2), Math.Max(mp1.Y2, mp2.Y2));
        }

        public MirrorPlane flipBy(MirrorPlane p)
        {
            if (p.isHorizontal())
            {
                return new MirrorPlane(this.X1, p.Y1 - (this.Y1 - p.Y1), this.X2, p.Y1 - (this.Y2 - p.Y1));
            }
            else
            {
                return new MirrorPlane(p.X1 - (this.X1 - p.X1), this.Y1, p.X1 - (this.X2 - p.X1), this.Y2);
            }
        }
    }

    public class Player
    {
        public double X;
        public double Y;
        public List<MirrorPlane> crosedPlanes = new List<MirrorPlane>();

        public Player(double X, double Y)
        {
            this.X = X;
            this.Y = Y;
        }

        public bool visibleFrom(double X, double Y, int distance, List<Player> players)
        {
            double diffX = this.X - X;
            double diffY = this.Y - Y;
            if ((diffX == 0) && (diffY == 0)) return false;
            double angle = Math.Atan2(diffY, diffX);
            double sqrdPlayerDistance = diffX * diffX + diffY * diffY;
            if (distance * distance < sqrdPlayerDistance) return false;
            foreach (Player p in players)
            {
                if (p != this)
                {
                    double pdiffX = p.X - X;
                    double pdiffY = p.Y - Y;
                    if ((pdiffX != 0) || (pdiffY != 0))
                    {
                        double psqrdPlayerdistance = pdiffX * pdiffX + pdiffY * pdiffY;
                        if (psqrdPlayerdistance < sqrdPlayerDistance)
                        {
                            if (Math.Abs(Math.Atan2(pdiffY, pdiffX) - angle) == 0) return false;
                        }
                    }
                }
            }
            foreach (MirrorPlane cPlane in crosedPlanes)
            {
                if (!cPlane.crossedBy(X, Y, this.X, this.Y))
                {
                    return false;
                }
            }
            return true;
        }

        public void flipBy(MirrorPlane p)
        {
            if (p.isHorizontal())
            {
                this.Y = p.Y1 - (this.Y - p.Y1);
            }
            else
            {
                this.X = p.X1 - (this.X - p.X1);
            }
        }
    }
}
