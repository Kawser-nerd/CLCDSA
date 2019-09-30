using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int itemCount = int.Parse(Reader.ReadLine());
        int[] timeArr = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        int[] spdArr = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        for (int i = 0; i < itemCount; i++) {
            this.AreaList.Add(new Area(i, timeArr[i], spdArr[i]));
        }
        this.AreaList[0].EnterMaxSpeed = 0;
        this.AreaList.Last().LeaveMaxSpeed = 0;
        if(this.AreaList.Count>1) {
            this.AreaList[0].LeaveMaxSpeed = Math.Min(this.AreaList[0].LeaveMaxSpeed, this.AreaList[1].EnterMaxSpeed);
        }
        Queue<Area> que = new Queue<Area>();
        que.Enqueue(this.AreaList[0]);
        while(que.Count>0) {
            Area current = que.Dequeue();
            if(!current.IsModified) {
                continue;
            }
            current.IsModified = false;
            if(current.ID>0) {
                Area prev = this.AreaList[current.ID - 1];
                prev.LeaveMaxSpeed = Math.Min(prev.LeaveMaxSpeed, current.EnterMaxSpeed);
                que.Enqueue(prev);
            }
            if(current.ID<this.AreaList.Count-1) {
                Area next = this.AreaList[current.ID + 1];
                next.EnterMaxSpeed = Math.Min(next.EnterMaxSpeed, current.LeaveMaxSpeed);
                que.Enqueue(next);
            }
        }
        decimal ans = AreaList.Sum(a => a.GetLength());
        Console.WriteLine(ans);
    }

    List<Area> AreaList = new List<Area>();

    private class Area {
        public int ID;
        public int MaxSpeed;
        public int Time;
        private int ValueOfEnterMaxSpeed;
        private int ValueOfLeaveMaxSpeed;
        public bool IsModified = false;
        public int EnterMaxSpeed {
            get {
                return this.ValueOfEnterMaxSpeed;
            }
            set {
                int spd = Math.Min(this.MaxSpeed, value);
                if(this.LeaveMaxSpeed-spd>Time) {
                    this.LeaveMaxSpeed = spd + Time;
                } else if(spd-this.LeaveMaxSpeed>Time) {
                    spd = this.LeaveMaxSpeed - Time;
                }
                this.IsModified = IsModified || (this.ValueOfEnterMaxSpeed != spd);
                this.ValueOfEnterMaxSpeed = spd;
            }
        }
        public int LeaveMaxSpeed {
            get {
                return this.ValueOfLeaveMaxSpeed;
            }
            set {
                int spd = Math.Min(this.MaxSpeed, value);
                if(this.EnterMaxSpeed-spd>Time) {
                    this.EnterMaxSpeed = spd + Time;
                } else if(spd-this.EnterMaxSpeed>Time) {
                    spd = this.EnterMaxSpeed + Time;
                }
                this.IsModified = this.IsModified || (this.ValueOfLeaveMaxSpeed != spd);
                this.ValueOfLeaveMaxSpeed = spd;
            }
        }

        public decimal GetLength() {
            decimal x = (this.LeaveMaxSpeed + Time - this.EnterMaxSpeed) / 2m;
            decimal y = x + this.EnterMaxSpeed;
            decimal ans = 0;
            y = Math.Min(y, this.MaxSpeed);
            decimal kasoku = y - this.EnterMaxSpeed;
            ans += (this.EnterMaxSpeed + y) * kasoku / 2m;
            decimal gensoku = y - this.LeaveMaxSpeed;
            ans += (this.LeaveMaxSpeed + y) * gensoku / 2m;
            ans += (this.Time - kasoku - gensoku) * y;
            return ans;
        }

        public Area(int id, int time, int max) {
            this.ID = id;
            this.Time = time;
            this.MaxSpeed = max;
            this.ValueOfEnterMaxSpeed = max;
            this.LeaveMaxSpeed = max;
            this.IsModified = true;
        }

    }

    public class Reader
    {
        private static StringReader sr;
        public static bool IsDebug = false;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (sr == null)
                {
                    sr = new StringReader(InputText.Trim());
                }
                return sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        private static string InputText = @"


10
64 55 27 35 76 119 7 18 49 100
29 19 31 39 27 48 41 87 55 70

";
    }

    public static void Main(string[] args)
    {
#if DEBUG
        Reader.IsDebug = true;
#endif
        Program prg = new Program();
        prg.Proc();
    }
}