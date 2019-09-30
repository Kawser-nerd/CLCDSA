using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {        
        static int nextTask(char rcolor, int from, string[] task)
        {
            for (int c = from;c<task.Length;c+=2)
            {
                if (task[c][0] == rcolor) return int.Parse(task[c + 1]);
            }
            return -1;
        }
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader(args[0]);
            var cases = int.Parse(tr.ReadLine());
            for(int caseN = 0;caseN<cases;caseN++)
            {
                Console.Write("Case #"+(caseN+1)+": ");
                var need = tr.ReadLine().Split(' ');
                int buttons = int.Parse(need[0]);
                /*for (int cb = 0;cb<buttons;cb++)
                {
                    
                }*/
                int ctask = 1;
               
                var opos = 1;
                
                var bpos = 1;
                bool complete = false;
                int tick = 0;
                while (!complete)
                {                    
                    var otask = nextTask('O', ctask, need);
                    var btask = nextTask('B', ctask, need);
                    var odone = false;
                    var bdone = false;
                    if (ctask == need.Length)
                    {
                        complete = true; continue;                        
                    }
                    if (otask != opos)
                    {
                        opos = opos > otask ? (opos - 1) : (opos + 1);
                        odone = true;
                    }
                    if (btask != bpos)
                    {
                        bpos = bpos > btask ? (bpos - 1) : (bpos + 1);
                        bdone = true;
                    }  
                    if (need[ctask][0]=='O' && !odone && opos==otask)
                    {
                        // o push
                        ctask += 2;
                    } else
                    if (need[ctask][0] == 'B' && !bdone && bpos == btask)
                    {
                        // b push
                        ctask += 2;
                        
                    }
                    tick++;
                }
                Console.WriteLine(tick);
            }
            Console.ReadKey();

        }
    }
}

