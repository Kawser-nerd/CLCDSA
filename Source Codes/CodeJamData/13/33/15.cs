using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamManager
{

    public class Tribe
    {
        public int cAttackFrom; 
        public int cAttackTo;
        public int cStrength; 
        public int cDeltaMove; 
        public int cDeltaStrength;
        public bool lastAttackSuccess; 
    }

    class R1C_3_2013 : SolutionBase
    {
        const int wallOffset = 500;
        public override void ProcessOne(int processNumber, System.IO.StreamReader input, System.IO.StreamWriter output)
        {
            int result = 0;
            int[] wall = new int[1000];
            int tribesNo = ReadLineAsInt();
            List<Tribe> tribes = new List<Tribe>(tribesNo);
            List<KeyValuePair<int, int>> attackMap = new List<KeyValuePair<int, int>>();
            int attackLefts = 0;
            for (int t = 0; t < tribesNo; t++)
            {
                int[] data = ReadLineAsIntTable();
                //di, ni, wi, ei, si, delta_di, delta_pi and delta_s
                int firsAttak = data[0];
                int attacks = data[1];
                int attackFrom = data[2];
                int attackTo = data[3];
                int strength = data[4];
                int deltaAttack = data[5];
                int deltaMove = data[6];
                int deltaStrength = data[7];

                attackLefts += attacks;
                tribes.Add(new Tribe() { cAttackFrom = attackFrom, cAttackTo = attackTo, cStrength = strength, cDeltaMove = deltaMove, cDeltaStrength = deltaStrength });
                for (int i = 0; i < attacks; i++)
                {
                    attackMap.Add(new KeyValuePair<int, int>(firsAttak, t));
                    firsAttak += deltaAttack;
                }
            }

            
            int time = 0;
            while (attackLefts > 0)
            {
                int min = int.MaxValue;
                foreach (KeyValuePair<int, int> n in attackMap)
                {
                    if (n.Key >= time)
                    {
                        if (n.Key < min) min = n.Key;
                    }
                }
                time = min + 1;
                IEnumerable<KeyValuePair<int, int>> next = attackMap.Where(k => k.Key == min);
                foreach (KeyValuePair<int, int> atak in next)
                {
                    Tribe t = tribes[atak.Value];
                    //check if wall ok
                    bool wallok = true;
                    for (double i = t.cAttackFrom; i <= t.cAttackTo; i+=0.5)
                    {
                        if (wall[(int)(i*2 + wallOffset)] < t.cStrength)
                        {
                            wallok = false;
                            break;
                        }
                    }
                    t.lastAttackSuccess = !wallok;
                
                }

                foreach (KeyValuePair<int, int> atak in next)
                {
                    Tribe t = tribes[atak.Value];
                    if (t.lastAttackSuccess)
                    {
                        result++;
                        for (double i = t.cAttackFrom; i <= t.cAttackTo; i+=0.5)
                        {
                            if (wall[(int)(i * 2 + wallOffset)] < t.cStrength)
                            {
                                wall[(int)(i * 2 + wallOffset)] = t.cStrength;
                            }
                        }
                    }
                    t.cStrength += t.cDeltaStrength;
                    t.cAttackFrom += t.cDeltaMove;
                    t.cAttackTo += t.cDeltaMove;
                    t.lastAttackSuccess = false;
                    attackLefts--;
                }


            
            }

            base.StoreResults(output, processNumber, result);
        }
    }
}
