using System.IO;
using System.Linq;

namespace GreatWall
{
    struct Attack
    {
        public int AttackNumber;
        public int Day;
        public int StartPos;
        public int EndPos;
        public int Strength;
    }
    
    class Wall
    {
        private int[] heights = new int[400];

        public bool CanAttack(int left, int right, int height)
        {
            for (var i = left + 200; i < right + 200; i++)
            {
                if (heights[i] < height) return true;
            }
            return false;
        }

        public void Build(int left, int right, int height)
        {
            for (var i = left + 200; i < right + 200; i++)
            {
                if (heights[i] < height) heights[i] = height;
            }
        }
    }

    internal class Program
    {
        private struct AttackSchedule
        {
            public int NumberOfAttacks;
            public Attack FirstAttack;
            public int DeltaDays;
            public int DeltaPosition;
            public int DeltaStrength;

            public void GetNextAttack(ref Attack a)
            {
                a.AttackNumber++;
                if (a.AttackNumber >= NumberOfAttacks)
                {
                    a = new Attack() { Day = int.MaxValue };
                }
                else
                {
                    a.Day += DeltaDays;
                    a.StartPos += DeltaPosition;
                    a.EndPos += DeltaPosition;
                    a.Strength += this.DeltaStrength;
                }
            }

        }

        private static void Main(string[] args)
        {
            var fileName = "c:\\temp\\1C\\C-small.in";
            using (var reader = new StreamReader(fileName))
            using (var writer = new StreamWriter(Path.ChangeExtension(fileName, "out")))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseID = 1; caseID <= count; caseID++)
                {
                    var attackers = int.Parse(reader.ReadLine());
                    var schedule = new AttackSchedule[attackers];

                    for (var attackID = 0; attackID < attackers; attackID++)
                    {
                        var row = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                        schedule[attackID].FirstAttack.Day = row[0];
                        schedule[attackID].NumberOfAttacks = row[1];
                        schedule[attackID].FirstAttack.StartPos = row[2];
                        schedule[attackID].FirstAttack.EndPos = row[3];
                        schedule[attackID].FirstAttack.Strength = row[4];
                        schedule[attackID].DeltaDays = row[5];
                        schedule[attackID].DeltaPosition = row[6];
                        schedule[attackID].DeltaStrength = row[7];
                    }

                    var successfulAttacks = GetSuccessfulAttacks(schedule);

                    writer.WriteLine("Case #{0}: {1}", caseID, successfulAttacks);
                    writer.Flush();
                }
            }
        }

        private static long GetSuccessfulAttacks(AttackSchedule[] schedule)
        {
            long successfulAttacks=0;
            var attacks = schedule.Select(s => s.FirstAttack).ToArray();

            Wall wall = new Wall();

            while (true)
            {
                var minDay = int.MaxValue;
                for (var i = 0; i < attacks.Length; i++)
                {
                    if (attacks[i].Day < minDay) minDay = attacks[i].Day;
                }

                if (minDay == int.MaxValue) return successfulAttacks;

                // attack
                for (var i = 0; i < attacks.Length; i++)
                {
                    if (attacks[i].Day == minDay)
                    {
                        if (wall.CanAttack(attacks[i].StartPos, attacks[i].EndPos, attacks[i].Strength)) successfulAttacks++;
                    }
                }

                // build (and move to next attack)
                for (var i = 0; i < attacks.Length; i++)
                {
                    if (attacks[i].Day == minDay)
                    {
                        wall.Build(attacks[i].StartPos, attacks[i].EndPos, attacks[i].Strength);
                        schedule[i].GetNextAttack(ref attacks[i]);
                    }
                }
            }
        }
    }
}
