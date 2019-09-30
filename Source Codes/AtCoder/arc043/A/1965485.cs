using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SandboxCSharp
{
    class Solver
    {

        public void Solve()
        {
            var n = io.ScanInt();
            var a = io.ScanDouble();
            var b = io.ScanDouble();

            var scores = Enumerable.Range(1, n).Select((e) => io.ScanDouble()).ToArray();

            double mulHigh = 1e18, mulLow = 0;

            for (int lop = 0; lop < 100; ++lop)
            {
                var mid = (mulHigh + mulLow) / 2;

                var seq = scores.Select((e) => (e * mid));
                var d = seq.Max() - seq.Min();

                if (d < b)
                {
                    mulLow = mid;
                }
                else
                {
                    mulHigh = mid;
                }
            }

            var mul = mulLow;

            var v = scores.Select(e => (e * mul)).Average();
            
            if (mul >= 1e18 - 1e15)
                io.WriteLine("-1");
            else
                io.WriteLine($"{mul} {a - v}");
        }

        // =================================================
        // =================================================

        Stdio io;
        bool isjdg;
        static void Main()
        {
            var s = new Solver();
            s.Solve();
            s.io.Flush();
        }
        public Solver(Stdio _io = null)
        {
            isjdg = _io == null;
            io = _io == null ? new Stdio() : _io;
        }

        void Exit()
        {
            if (isjdg)
            {
                io.Flush();
                Environment.Exit(0);
            }
            else
                throw new HaltException();
        }
    }
    class Stdio
    {
        protected string[] stack = new string[0];
        protected int stackptr = 0;
        protected StringBuilder outbuff = new StringBuilder();

        public virtual int ScanInt()
        {
            return Check() ? int.Parse(stack[stackptr++]) : 0;
        }
        public virtual long ScanLong()
        {
            return Check() ? long.Parse(stack[stackptr++]) : 0;
        }
        public virtual string ScanString()
        {
            return Check() ? stack[stackptr++] : string.Empty;
        }
        public virtual double ScanDouble()
        {
            return Check() ? double.Parse(stack[stackptr++]) : 0;
        }
        protected virtual bool Check()
        {
            if (stackptr < stack.Length) return true;
            var l = Console.ReadLine();
            if (l == null) return false;
            stack = l.Split(' ').ToArray(); stackptr = 0;
            return Check();
        }
        public Stdio Write(long v) { return Write($"{v}"); }
        public Stdio WriteLine(long v) { return WriteLine($"{v}"); }
        public Stdio Write(string str)
        {
            outbuff.Append(str);
            return this;
        }
        public Stdio WriteLine(string str = "")
        {
            outbuff.AppendLine(str);
            return this;
        }
        public virtual Stdio Flush()
        {
            Console.Write(outbuff.ToString());
            outbuff.Clear();
            return this;
        }
    }
    class HaltException : Exception { }

}