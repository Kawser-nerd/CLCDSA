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
            var h = io.ScanLong();
            var m = io.ScanLong();

            var x = 0l;

            x += (18 - h - 1) * 60;
            x += (60 - m);

            io.WriteLine($"{x}");
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