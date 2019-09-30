using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2008.TrainTimetable
{
    class Program
    {
        //enum TrainStates { TrainIsReadyInA, TrainIsReadyInB, TrainIsLeavingA, TrainIsLeavingB }

        //static int CA { set; get; }

        static void Main(string[] args)
        {
            int time = System.Environment.TickCount;
            TextReader r = new StreamReader("input.txt");
            
            int N = int.Parse(r.ReadLine());
            
            for (int n = 1; n <= N; n++)
            {
                int turnaround = int.Parse(r.ReadLine());

                string[] nums = r.ReadLine().Split(' ');
                int NA = int.Parse(nums[0]);
                int NB = int.Parse(nums[1]);

                var events = new List<TrainState>();
                var AStation = new TrainStation();
                var BStation = new TrainStation();

                for (int i = 0; i < NA + NB; i++)
                {
                    string[] times = r.ReadLine().Split(' ');

                    int t = 0;
                    
                    t = int.Parse(times[0].Replace(":", ""));
                    t = t % 100 + (t / 100) * 60;
                    events.Add(new TrainIsLeaving(i < NA ? AStation : BStation, t));
                    
                    t = int.Parse(times[1].Replace(":", ""));
                    t = t % 100 + (t / 100) * 60;
                    events.Add(new TrainIsReady(i < NA ? BStation : AStation, t + turnaround ));
                }

                events.Sort();
                foreach (TrainState state in events)
                    state.Process();

                Console.WriteLine("Case #{0}: {1} {2}", n, -AStation.Minimum, -BStation.Minimum);
            }
            //Console.ReadLine();
        }
    }

    class TrainStation
    {
        int trainsReady = 0;
        public int Minimum { get; private set; }

        public TrainStation()
        {
            Minimum = 0;
        }

        public void TrainIsReady()
        {
            trainsReady++;
        }

        public void TrainIsLeaving()
        {
            if (--trainsReady < Minimum) Minimum = trainsReady;
        }
    }

    abstract class TrainState: IComparable
    {
        protected int Time { set; get; }
        protected int Priority { set; get; }
        protected TrainStation Station { set; get; }
        
        protected TrainState(TrainStation station, int time, int priority)
        {
            this.Time = time;
            this.Station = station;
            this.Priority = priority;
        }

        abstract public void Process();

        #region IComparable Members

        int IComparable.CompareTo(object obj)
        {
            if (obj is TrainState)
            {
                return (Time * 10 + Priority).CompareTo((obj as TrainState).Time * 10 + (obj as TrainState).Priority);
            }

            return 0;
        }

        #endregion
    }

    class TrainIsLeaving: TrainState
    {
        public TrainIsLeaving(TrainStation station, int time):base(station, time, 5) { }

        public override void Process()
        {
            base.Station.TrainIsLeaving();
        }
    }

    class TrainIsReady : TrainState
    {
        public TrainIsReady(TrainStation station, int time) : base(station, time, 1) { }

        public override void Process()
        {
            base.Station.TrainIsReady();
        }
    }
}
