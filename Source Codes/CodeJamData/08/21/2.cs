using System;
using System.Collections.Generic;
using System.Text;

class Program {

    static void Main() {
        M1();
        //M2();
        //M3();
    }

    static void M1() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            CropTriangles o = new CropTriangles();

            string s = Console.ReadLine();

            string sOut = o.Process(s);
            Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M2() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            //MinimumScalarProduct o = new MinimumScalarProduct();

            string s = Console.ReadLine();

            //string sOut = o.Process(a, b);
            //Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M3() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            //MinimumScalarProduct o = new MinimumScalarProduct();

            string s = Console.ReadLine();

            //string sOut = o.Process(a, b);
            //Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }
    
    static void M1Old() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            MinimumScalarProduct o = new MinimumScalarProduct();

            string s2 = Console.ReadLine();
            int nn = int.Parse(s2);
            int[] a = new int[nn];
            int[] b = new int[nn];
            string[] s3 = Console.ReadLine().Split(' ');
            for (int j = 0; j < nn; j++) {
                a[j] = int.Parse(s3[j]);
            }
            s3 = Console.ReadLine().Split(' ');
            for (int j = 0; j < nn; j++) {
                b[j] = int.Parse(s3[j]);
            }

            string sOut = o.Process(a, b);
            //string sOut = o.ProcessPair(Console.ReadLine(), Console.ReadLine());
            Console.WriteLine("Case #{0}: {1}", i + 1, sOut);

        }

        if (bManual) Console.ReadKey();
    }

    static void M2Old() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            Milkshakes o = new Milkshakes();

            string s = Console.ReadLine();
            int F = int.Parse(s);
            int C = int.Parse(Console.ReadLine());
            string[] cust = new string[C];
            for (int j = 0; j < C; j++) {
                cust[j] = Console.ReadLine();
            }

            string sOut = o.Process(F, cust);
            Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M3Old() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            //var o = new MinimumScalarProduct();

            //string sOut = o.Process(a, b);
            //Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M0() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            //MinimumScalarProduct o = new MinimumScalarProduct();

            string s = Console.ReadLine();

            //string sOut = o.Process(a, b);
            //Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }
}
